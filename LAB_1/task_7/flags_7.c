#include "flags_7.h"

void flag_r(const char* file_1, const char* file_2, const char* out_file)
{
    int count_1, count_2, merged_count;
   
    FILE* in_1 = fopen(file_1, "r");
    if (!in_1) {
        printf("Error opening file");
        return;
    }

    FILE* in_2 = fopen(file_2, "r");
    if (!in_2) {
        printf("Error opening file");
        return;
    }


    char** lexemes1 = read_lexemes(in_1, &count_1);
    char** lexemes2 = read_lexemes(in_2, &count_2);

    char** merged_lexemes = merge_lexemes(lexemes1, count_1, lexemes2, count_2, &merged_count);
    
    FILE* out = fopen(out_file, "w");
    if (!out) {
        printf("Error opening file");
        return;
    }

    write_lexemes_r(out, merged_lexemes, merged_count);

    free(lexemes1);
    free(lexemes2);
}

void flag_a(const char* file, const char* out_file)
{
    int count;
    
    FILE* in = fopen(file, "r");
    if (!in) {
        printf("Error opening file");
        return;
    }

    char** lexemes = read_lexemes(in, &count);

    FILE* out = fopen(out_file, "w");
    if (!out) {
        printf("Error opening file");
        return;
    }

    write_lexemes_a(out, lexemes, count);

    free(lexemes);
}

void execute_flag(int argc, char** argv)
{
    char *flag = argv[1];

    if (*flag == '-' || *flag == '/') {
        const char *in_file_1, *in_file_2;

        const char* out_file;

        if (argc == 4) {
            in_file_1 = argv[2];
            out_file = argv[3]; 
        } else if (argc == 5) {
            in_file_1 = argv[2];
            in_file_2 = argv[3];
            out_file = argv[4];
        } else {
            printf("Incorrect number of arguments\n");
            return;
        }

        switch (*(flag + 1))
        {
        case 'r':
            flag_r(in_file_1, in_file_2, out_file);
            break;

        case 'a':
            flag_a(in_file_1, out_file);
            break;

        default:
            printf("Flag is not finded\n");
            break;
        }
    } else {
        printf("Use - or / to use flag\n");
    }
}