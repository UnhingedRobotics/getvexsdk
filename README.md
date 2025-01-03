# Vex SDK Fetch Tool

**getvexsdk** is a utility designed to download the latest VEX SDK, facilitating its integration into your projects. This tool simplifies obtaining the SDK, ensuring compliance with licensing requirements, and streamlining development workflows.

## Features

- **Automated SDK Retrieval**: Downloads the latest version of the VEX SDK directly from the official source.
- **Seamless Integration**: Prepares the SDK for immediate use in your projects, such as [vexcodetext](https://github.com/UnhingedRobotics/vexcodetext).
- **Licensing Compliance**: Ensures that the SDK is obtained in accordance with VEX's licensing terms.

## Inspiration and Acknowledgments

This project draws significant inspiration from [Jerrylum's Python script](https://gist.github.com/Jerrylum/411d5eed30276d41b3fae1f98cc7dc5c), which automates the download and extraction of the VEX SDK. Special thanks to [Jerrylum](https://github.com/Jerrylum) for providing insights and explanations that contributed to the development of this tool.

## Dependencies

The `getvexsdk` utility is implemented in C++ and utilizes standard libraries. To build and run this tool on Linux, ensure that you have the following installed:

- **C++ Compiler**: A C++17 compatible compiler, such as `g++`.
- **Make**: A build automation tool, such as `make`.

### Installation Steps on Linux

#### Debian/Ubuntu

1. **Update Package List**:
   ```bash
   sudo apt update
2. **Install Dependencies**:

   ```bash
    sudo apt install build-essential
    ```

    The build-essential package includes g++ and make.

### Fedora

1. **Install Dependencies**:

   ```bash
    sudo dnf groupinstall "Development Tools"
   ```
    This group includes g++ and make.

### Arch Linux

1. **Install Dependencies**:

   ```bash
   sudo pacman -S base-devel
   ```

    The base-devel group includes g++ and make.

## Building and Running the Utility

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/UnhingedRobotics/getvexsdk.git
    ```

    Navigate to the cloned directory:
    
    ```bash
    cd getvexsdk
    ```

2. **Build the Utility**:

    ```bash
    make
    ```

3. **Run the Utility**: After a successful build, execute the program:

    ```bash
    ./getvexsdk
    ```

## Usage

Upon execution, getvexsdk will:

1. Download the latest VEX SDK archive.
2. Extract the contents to a specified directory.
3. Prepare the SDK for integration into your projects.

For detailed usage instructions and options, refer to the documentation.

## License

This project is licensed under the MIT License. For more details, see the [LICENSE](https://github.com/UnhingedRobotics/getvexsdk/blob/main/LICENSE) file.

---

***Note: Always ensure that you comply with VEX's licensing terms when using their SDK in your projects.***
