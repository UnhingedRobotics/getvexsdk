// check_sdk.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>      // For strlen
#include <filesystem>   // For std::filesystem
#include <curl/curl.h>  // For libcurl
#include <zip.h>        // For libzip

namespace sdk_downloader {

// Helper function for libcurl to write data to a file
size_t writeToFile(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to download a file using libcurl
void downloadFile(const std::string& url, const std::string& outputPath) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }

    FILE* file = fopen(outputPath.c_str(), "wb");
    if (!file) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("Failed to open output file");
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToFile);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    CURLcode res = curl_easy_perform(curl);
    fclose(file);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        throw std::runtime_error("CURL download failed: " + std::string(curl_easy_strerror(res)));
    }
}

// Function to extract a zip file using libzip
void extractZip(const std::string& zipPath, const std::filesystem::path& outputDir) {
    int err;
    zip_t* archive = zip_open(zipPath.c_str(), ZIP_RDONLY, &err);
    if (!archive) {
        throw std::runtime_error("Failed to open zip archive");
    }

    std::filesystem::create_directories(outputDir);

    zip_int64_t numEntries = zip_get_num_entries(archive, 0);
    for (zip_uint64_t i = 0; i < numEntries; ++i) {
        const char* name = zip_get_name(archive, i, 0);
        if (!name) {
            zip_close(archive);
            throw std::runtime_error("Failed to get zip entry name");
        }

        std::filesystem::path filePath = outputDir / name;
        if (name[strlen(name) - 1] == '/') {
            std::filesystem::create_directories(filePath);
        } else {
            zip_file_t* zf = zip_fopen_index(archive, i, 0);
            if (!zf) {
                zip_close(archive);
                throw std::runtime_error("Failed to open zip file entry");
            }

            std::ofstream outFile(filePath, std::ios::binary);
            if (!outFile.is_open()) {
                zip_fclose(zf);
                zip_close(archive);
                throw std::runtime_error("Failed to create output file");
            }

            char buffer[4096];
            zip_int64_t bytesRead;
            while ((bytesRead = zip_fread(zf, buffer, sizeof(buffer))) > 0) {
                outFile.write(buffer, bytesRead);
            }

            zip_fclose(zf);
            outFile.close();
        }
    }

    zip_close(archive);
}

} // namespace sdk_downloader
