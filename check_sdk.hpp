// check_sdk.hpp
#ifndef CHECK_SDK_HPP
#define CHECK_SDK_HPP

#include <string>
#include <filesystem>

namespace sdk_downloader {

// Downloads a file from the specified URL and saves it to the output path
void downloadFile(const std::string& url, const std::string& outputPath);

// Extracts the contents of a zip file to the specified output directory
void extractZip(const std::string& zipPath, const std::filesystem::path& outputDir);

} // namespace sdk_downloader

#endif // CHECK_SDK_HPP
