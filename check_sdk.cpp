#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <curl/curl.h>
#include <zip.h>
#include <cstring> // For strlen
#include <nlohmann/json.hpp> // For JSON parsing
#include <cstdlib> // For getenv

namespace fs = std::filesystem;

size_t writeToFile(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void downloadFile(const std::string& url, const std::string& outputPath) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize curl");
    }

    FILE* file = fopen(outputPath.c_str(), "wb");
    if (!file) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("Failed to open file for writing: " + outputPath);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToFile);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fclose(file);
        curl_easy_cleanup(curl);
        throw std::runtime_error("Failed to download file: " + std::string(curl_easy_strerror(res)));
    }

    fclose(file);
    curl_easy_cleanup(curl);
}

void extractZip(const std::string& zipPath, const fs::path& outputPath) {
    int err;
    zip* archive = zip_open(zipPath.c_str(), 0, &err);
    if (!archive) {
        throw std::runtime_error("Failed to open zip archive");
    }

    zip_uint64_t numEntries = zip_get_num_entries(archive, 0);
    for (zip_uint64_t i = 0; i < numEntries; ++i) {
        const char* name = zip_get_name(archive, i, 0);
        if (!name) {
            zip_close(archive);
            throw std::runtime_error("Failed to get entry name");
        }

        fs::path filePath = outputPath / name;

        if (name[strlen(name) - 1] == '/') {
            fs::create_directories(filePath);
        } else {
            zip_file* file = zip_fopen_index(archive, i, 0);
            if (!file) {
                zip_close(archive);
                throw std::runtime_error("Failed to open file in zip");
            }

            fs::create_directories(filePath.parent_path());

            std::ofstream outFile(filePath, std::ios::binary);
            if (!outFile) {
                zip_fclose(file);
                zip_close(archive);
                throw std::runtime_error("Failed to create output file");
            }

            char buffer[4096];
            zip_int64_t bytesRead;
            while ((bytesRead = zip_fread(file, buffer, sizeof(buffer))) > 0) {
                outFile.write(buffer, bytesRead);
            }

            zip_fclose(file);
        }
    }

    zip_close(archive);
}

int main() {
    try {
        // Determine temporary directory for Windows
        const char* tempDir = getenv("TEMP");
        if (!tempDir) {
            throw std::runtime_error("Temporary directory not found");
        }
        fs::path tempPath = tempDir;

        std::string manifestUrl = "https://content.vexrobotics.com/vexos/public/V5/vscode/sdk/cpp/manifest.json";
        fs::path manifestFile = tempPath / "manifest.json";
        fs::path tempZipFile = tempPath / "libv5rt.zip";

        // Download manifest.json
        downloadFile(manifestUrl, manifestFile.string());

        // Parse manifest.json
        std::ifstream inFile(manifestFile);
        if (!inFile) {
            throw std::runtime_error("Failed to open manifest.json");
        }

        nlohmann::json manifest;
        inFile >> manifest;
        std::string latestVersion = manifest["latest"];
        std::cout << "Latest SDK version: " << latestVersion << "\n";

        // Construct the SDK download URL
        std::string sdkUrl = "https://content.vexrobotics.com/vexos/public/V5/vscode/sdk/cpp/" + latestVersion + ".zip";

        // Download the SDK zip
        std::cout << "Downloading SDK...\n";
        downloadFile(sdkUrl, tempZipFile.string());

        // Extract the SDK
        fs::path sdkOutputDir = "sdk"; // Define your SDK output directory
        std::cout << "Extracting SDK to " << sdkOutputDir << "\n";
        extractZip(tempZipFile.string(), sdkOutputDir);

        std::cout << "SDK successfully downloaded and extracted to " << sdkOutputDir << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
