#include "functions_8.h"

int validate_args(int argc, char** argv)
{
    if (argc < 3) {
        printf("Usage: %s <in_file> <out_file>\n", argv[0]);
        return 1;
    }
}

void process_files(FILE* in, FILE* out)
{
    long long size = get_file_size(in);
    char buffer[size];

    while (fscanf(in, "%s", buffer) == 1) {
        int base = min_base(buffer);
        long long decimal = to_decimal(buffer, base);
        fprintf(out, "%s %d %lld\n", buffer, base, decimal);
    }
}

int min_base(const char* num) {
    int base = 2;

    for (const char* p = num; *p; p++) {
        char c = tolower(*p);
        int value = (isdigit(c)) ? c - '0' : c - 'a' + 10;
        if (value + 1 > base) {
            base = value + 1;
        }
    }

    return base;
}

long long to_decimal(const char* num, int base) {
    long long result = 0;

    for (const char* p = num; *p; p++) {
        char c = tolower(*p);
        int value = (isdigit(c)) ? c - '0' : c - 'a' + 10;
        result = result * base + value;
    }

    return result;
}

long long get_file_size(FILE* file) {
    fseek(file, 0, SEEK_END);

    long long size = ftell(file);

    fseek(file, 0, SEEK_SET);

    return size;
}