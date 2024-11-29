#include "../inc/core.hpp"
#include <stdio.h>

#define INVALID_USAGE 1
#define EXCEPTION 2
#define UNKNOWN_ERROR 3
#define SUCCESS 0

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <flag>" << std::endl;
        return INVALID_USAGE;
    }

    try {
        std::vector<std::byte> key = {std::byte(0x00000003)};

        Encoder encoder = Encoder(key);

        const char* in_file = argv[1];
        const char* out_file = argv[2];
        const char* flag = argv[3];

        std::string in {in_file};
        std::string out {out_file};
        bool f = (std::string{flag} == "True" || std::string{flag} == "true");

        encoder.process_file(in, out, f);
        
        std::cout << "Processing completed. Check the output file: " << out << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error:" << e.what() << std::endl;
        return EXCEPTION;
    } catch (...) {
        std::cerr << "Unknown error." << std::endl;
        return UNKNOWN_ERROR;
    }

    return SUCCESS;
}