#include "dictionary.h"

struct my_struct *dictionary = NULL;

void add_record(char *word, int neg, int pos, int uncert,
    int litig, int constrain, int superf, int interest, int modal) {
    struct my_struct *s;

    HASH_FIND_INT(dictionary, word, s);  /* id already in the hash? */
    if (s==NULL) {
        s = (struct my_struct *)malloc(sizeof *s);
        strcpy(s->id, word);
        s->Negative = neg;
        s->Positive = pos;
        s->Uncertainty = uncert;
        s->Litigious = litig;
        s->Constraining = constrain;
        s->Superfluous = superf;
        s->Interesting = interest;
        s->Modal = modal;
        HASH_ADD_INT( dictionary, id, s );  /* id: name of key field */
    }
}

struct my_struct *find_record(char *word) {
    struct my_struct *s;

    HASH_FIND_INT( dictionary, word, s );  /* s: output pointer */
    return s;
}

void print_dictionary() {
    struct my_struct *s;

    for(s=dictionary; s != NULL; s=(struct my_struct*)(s->hh.next)) {
        printf("word %s: pos %d, neg %d, uncert %d, lit %d, mod %d \n",
            s->id, s->Positive, s->Negative, s->Uncertainty, s->Litigious, s->Modal);
    }
}

void loadDictionary(char file[], int max) {
    int i, j; // iterators
    char *row[20]; // max 20 columns
    FILE* stream = fopen(file, "r"); // csv file
    char line[512];
    int ctr = 0; // max lines imported

    while (fgets(line, 512, stream) && (ctr < max))
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
        ctr++; // only for testing
    }

    // print_dictionary();
    printf("Dictionary Loaded (%d words)\n", max);

}
