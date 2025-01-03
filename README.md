# Vex SDK Fetch Tool

**getvexsdk** is a utility designed to download the latest VEX SDK, facilitating its integration into your projects. This tool aims to simplify the process of obtaining the SDK, ensuring compliance with licensing requirements, and streamlining development workflows.

## Features

- **Automated SDK Retrieval**: Downloads the latest version of the VEX SDK directly from the official source.
- **Seamless Integration**: Prepares the SDK for immediate use in your projects, such as [vexcodetext](https://github.com/UnhingedRobotics/vexcodetext).
- **Licensing Compliance**: Ensures that the SDK is obtained in accordance with VEX's licensing terms.

## Inspiration and Acknowledgments

This project draws significant inspiration from [Jerrylum's Python script](https://gist.github.com/Jerrylum/411d5eed30276d41b3fae1f98cc7dc5c), which automates the download and extraction of the VEX SDK. Special thanks to [Jerrylum](https://github.com/Jerrylum) for providing insights and explanations that contributed to the development of this tool.

## Dependencies

The `getvexsdk` utility is implemented in C++ and utilizes standard libraries. To build and run this tool on Windows, ensure that you have the following installed:

- **C++ Compiler**: A C++17 compatible compiler, such as [MinGW](http://www.mingw.org/) or [Microsoft Visual Studio](https://visualstudio.microsoft.com/).
- **Make**: A build automation tool, such as [GNU Make](http://gnuwin32.sourceforge.net/packages/make.htm) or [CMake](https://cmake.org/).

### Installation Steps on Windows

1. **Install a C++ Compiler**:
   - **MinGW**:
     - Download the installer from the [MinGW website](http://www.mingw.org/).
     - Run the installer and select the appropriate packages, including `gcc` and `g++`.
     - Add the MinGW `bin` directory to your system's PATH environment variable.
   - **Microsoft Visual Studio**:
     - Download the installer from the [Visual Studio website](https://visualstudio.microsoft.com/).
     - During installation, select the "Desktop development with C++" workload.

2. **Install Make**:
   - **GNU Make**:
     - Download the binary from the [GnuWin32 project](http://gnuwin32.sourceforge.net/packages/make.htm).
     - Extract the contents and add the `bin` directory to your system's PATH environment variable.
   - **CMake**:
     - Download the installer from the [CMake website](https://cmake.org/download/).
     - Run the installer and follow the prompts to complete the installation.
     - During installation, choose to add CMake to the system PATH for ease of use.

3. **Clone the Repository**:
   - Open a command prompt and execute:
     ```bash
     git clone https://github.com/UnhingedRobotics/getvexsdk.git
     ```
   - Navigate to the cloned directory:
     ```bash
     cd getvexsdk
     ```

4. **Build the Utility**:
   - If using GNU Make:
     ```bash
     make
     ```
   - If using CMake:
     ```bash
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```

5. **Run the Utility**:
   - After a successful build, execute the program:
     ```bash
     ./getvexsdk
     ```

## Usage

Upon execution, `getvexsdk` will:

1. Download the latest VEX SDK archive.
2. Extract the contents to a specified directory.
3. Prepare the SDK for integration into your projects.

For detailed usage instructions and options, refer to the [documentation](https://github.com/UnhingedRobotics/getvexsdk/wiki).

## License

This project is licensed under the MIT License. For more details, see the [LICENSE](https://github.com/UnhingedRobotics/getvexsdk/blob/main/LICENSE) file.

---

*Note: Always ensure that you comply with VEX's licensing terms when using their SDK in your projects.*
