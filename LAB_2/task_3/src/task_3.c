#include "../include/functions_2_3.h"

int main() 
{
    RESULT* res = get_matches("n\n\n\t\tb", "Tests/test_1.txt", "Tests/test_2.txt", NULL);
    if (res == NULL) {
        printf("Memory errors or empty input");
        return 1;
    }

    for (int i = 0; i < res[0].processed_file_count; i++) {
        if (res[i].status == DONE) {
            printf("%s %d\n", res[i].file_name, res[i].match_count);
            for (int j = 0; j < res[i].match_count; j++) {
                printf("%d %d\n", res[i].match_array[j].char_position, res[i].match_array[j].line_number);
            }

            free(res[i].match_array);
        } else {
            if (res[i].status == FILE_NOT_FOUND) {
                printf("ERROR: %s file not found\n", res[i].file_name);
                free(res);
                return 1;
            }
            else if (res[i].status == INVALID_MEMORY) {
                printf("ERROR: %s allocation memory error\n", res[i].file_name);
                free(res);
                return 1;
            }
        }
    }

    free(res);
    return 0;
}