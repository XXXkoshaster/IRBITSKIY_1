#include "functions_8.h"

int main(int argc, char* argv[])
{
    if(!(validate_args(argc, argv))) 
        return 1;

    const char* in_file = argv[1];
    const char* out_file = argv[2];

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
    
    process_files(in, out);

    fclose(in);
    fclose(out);

    return 0;
}
