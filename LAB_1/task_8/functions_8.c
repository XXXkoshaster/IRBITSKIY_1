#include "functions_8.h"

int validate_args(int argc, char** argv)
{
    if (argc != 3) {
        printf("Usage: %s <in_file> <out_file>\n", argv[0]);
        return 1;
    }
}

void process_files(FILE* in, FILE* out)
{
    char buffer[1024];

    fprintf(out, "Origin_value  Base  Decimal_value\n");

    while (fscanf(in, "%1023s", buffer) == 1) {
        int base = min_base(buffer);
        int decimal = to_decimal(buffer, base);
        fprintf(out, "%s %d %d\n", buffer, base, decimal);
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

int to_decimal(const char* num, int base) {
    int result = 0;

    for (const char* p = num; *p; p++) {
        char c = tolower(*p);
        int value = (isdigit(c)) ? c - '0' : c - 'a' + 10;
        
        if (value >= base) {
            printf("Invalid digit '%c' for base %d\n", c, base);
            return -1;
        }

        result = result * base + value;
    }

    return result;
}
