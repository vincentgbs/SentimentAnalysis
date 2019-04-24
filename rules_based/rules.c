#include "src/dictionary.h"
#include "src/parser.h"

#define REVIEWS 37126

int main() {
    loadDictionary("library/LoughranMcDonald_MasterDictionary_2018.csv", DICTLEN);
    getReviews("data/EDITED_REVIEWS.txt", "data/results.txt", REVIEWS);

    return 0;
}
