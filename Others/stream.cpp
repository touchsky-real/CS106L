#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int inputFileStreamExample() {
    namespace fs = std::filesystem;
    fs::path currentPath = fs::current_path();
    fs::path filePath = currentPath / "Others" / "append.txt";

    std::cout << "尝试打开文件：" << filePath << std::endl;

    std::ifstream ifs(filePath);
    if (!ifs.is_open()) {
        std::cerr << "无法打开文件！当前工作目录：" << currentPath << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << "Read from the file: " << line << '\n';
    }

    ifs.close();
    return 0;
}

int main() {
    /// associating file on construction
    std::ofstream ofs("hello.txt");
    if (ofs.is_open()) {
        ofs << "Hello CS106L!" << '\n';
    }
    ofs.close();

    ofs << "this will not get written";

    ofs.open("hello.txt", std::ios::app);
    ofs << "this will though! It's open again";

    inputFileStreamExample();

    return 0;
}
