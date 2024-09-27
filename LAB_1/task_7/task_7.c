#include "functions_7.h"

int main(int argc, char* argv[])
{
    int count_1, count_2, merged_count;

    FILE* file_1 = fopen(argv[1], "r");
    if (!file_1) {
        printf("Error opening file");
        return 1;
    }

    FILE* file_2 = fopen(argv[2], "r");
    if (!file_2) {
        printf("Error opening file");
        return 1;
    }

    char** lexemes1 = read_lexemes(file_1, &count_1);
    char** lexemes2 = read_lexemes(file_2, &count_2);

    char** merged_lexemes = merge_lexemes(lexemes1, count_1, lexemes2, count_2, &merged_count);

    FILE* out_file = fopen(argv[3], "w");
    if (!out_file) {
        printf("Error opening file");
        return 1;
    }

    write_lexemes(out_file, merged_lexemes, merged_count);

    free(lexemes1);
    free(lexemes2);

    return 0;
}