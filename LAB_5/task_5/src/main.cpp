#include <fstream>

#include "../inc/core.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::string discription = cdecl_translate(line);
        std::cout << discription << std::endl;
        std::cout << "-----" << std::endl;
    }

    file.close();

    return 0;
}