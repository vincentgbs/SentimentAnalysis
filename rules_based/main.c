#include "src/dictionary.h"
#include "src/parser.h"

#define REVIEWS 37126

int main() {
    loadDictionary("LoughranMcDonald_MasterDictionary_2018.csv", DICTLEN);
    getReviews("EDITED_REVIEWS.txt", "results.txt", REVIEWS);

    return 0;
}
