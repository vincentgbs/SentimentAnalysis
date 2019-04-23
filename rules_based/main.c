#include "src/dictionary.h"
#include "src/parser.h"

int main() {
    loadDictionary("LoughranMcDonald_MasterDictionary_2018.csv", DICTLEN);
    getReviews("EDITED_REVIEWS.txt", 99);
    return 0;
}
