#include "flags_4.h"

int  flag_d(const char* in_file, const char* out_file)
{   
    FILE* in = fopen(in_file, "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* out = fopen(out_file, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        return 1;
    }

    del_digits(in, out);

    fclose(in);
    fclose(out);

    return 0;
}

int  flag_i(const char* in_file, const char* out_file)
{   
    FILE* in = fopen(in_file, "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* out = fopen(out_file, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        return 1;
    }

    count_lat_letters(in, out);

    fclose(in);
    fclose(out);

    return 0;
}

int flag_s(const char* in_file, const char* out_file)
{   
    FILE* in = fopen(in_file, "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* out = fopen(out_file, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        return 1;
    }

    count_other_letters(in, out);

    fclose(in);
    fclose(out);

    return 0;
}

int  flag_a(const char* in_file, const char* out_file)
{   
    FILE* in = fopen(in_file, "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* out = fopen(out_file, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        return 1;
    }

    convert_to_ascii(in, out);

    fclose(in);
    fclose(out);

    return 0;
}

void execute_flag(char** argv)
{
    char *flag = argv[1];

    if (*flag == '-' || *flag == '/') {
        const char* in_file = argv[2];
        const char* out_file;
        int arg;

        if (*(flag + 1) == 'n') {
            out_file = argv[3]; 
            arg = *(flag + 2);
        } else {
            out_file = generate_out_file(in_file);
            arg = *(flag + 1);
        }

        switch (arg)
        {
        case 'd':
            flag_d(in_file, out_file);
            break;

        case 'i':
            flag_i(in_file, out_file);
            break;
        
        case 's':
            flag_s(in_file, out_file);
            break;

        case 'a':
            flag_a(in_file, out_file);
            break;

        default:
            printf("Flag is not finded\n");
            break;
        }
    } else {
        printf("Use - or / to use flag\n");
    }
}