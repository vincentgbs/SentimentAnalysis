#include "src/dictionary.h"
// #include "parser.h"

int main() {
    int i, j; // iterators
    char *row[20]; // max 20 columns
    FILE* stream = fopen("LoughranMcDonald_MasterDictionary_2018.csv", "r"); // csv file
    char line[512];
    int max = 0; // max lines (only for testing purposes)

    while (fgets(line, 512, stream) && (max < 9999))
    {
        char* str = strdup(line); // duplicate line as string
        char *p = strtok(str, ","); // split line on comas

        i = 0;
        while (p != NULL)
        {
            row[i++] = p;
            p = strtok(NULL, ",");
        }

        add_record(row[0], atoi(row[7]), atoi(row[8]), atoi(row[9]),
            atoi(row[10]), atoi(row[11]), atoi(row[12]), atoi(row[13]), atoi(row[14]));

        free(str); // deallocate memory from line pointer
        max++; // only for testing
    }

    printf("Done Loading\n");

    print_dictionary();

    // struct my_struct *s = find_record("AARDVARK");
    // printf("word %s: pos %i neg %i\n", s->id, s->Positive, s->Negative);
    //
    // s = find_record("ABANDONMENT");
    // printf("word %s: pos %i neg %i\n", s->id, s->Positive, s->Negative);

    return 0;
}
