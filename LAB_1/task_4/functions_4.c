#include "functions_4.h"

void del_digits(FILE* in_file, FILE* out_file)
{
    char ch;
    while ((ch = fgetc(in_file)) != EOF) {
        if (!isdigit(ch)) {
            fputc(ch, out_file);
        }
    }
}

void count_lat_letters(FILE* in_file, FILE* out_file)
{
    char line[1024];

    while (fgets(line, sizeof(line), in_file)) {
        int count = 0;
        
        for (int i = 0; line[i] != '\0'; i++) {
            if (isalpha(line[i])) {
                count++;
            }
        }

        fprintf(out_file, "Line: %sCount of latin alphabet characters: %d\n", line, count);
    }
}

void count_other_letters(FILE* in_file, FILE* out_file)
{
    char line[1024];

    while (fgets(line, sizeof(line), in_file)) {
        int count = 0;

        for (int i = 0; line[i] != '\0'; i++) {
            if (!(isalpha(line[i]) || isdigit(line[i]) || isspace(line[i]))) {
                count++;
            }
        }

        fprintf(out_file, "Line: %sCount of other characters: %d\n", line, count);
    }
}

void convert_to_ascii(FILE* in_file, FILE* out_file)
{
    int ch;
    while((ch = fgetc(in_file)) != EOF) {
        if (!isdigit(ch)) {
            fprintf(out_file, "%02X", ch);
        }
    }
}

const char* generate_out_file(const char* in_file)
{
    const char* prefix = "out_";

    char* out_file = (char*)malloc(strlen(prefix) + strlen(in_file) + 1);
    if (out_file == NULL) {
        printf("Error of emiting memory\n");
        return NULL;
    }

    strcpy(out_file, prefix);
    strcat(out_file, in_file);

    return out_file;
}
