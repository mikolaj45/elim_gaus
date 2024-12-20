#include "gauss.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    int res;
    Matrix * A = readFromFile(argv[1]);
    Matrix * b = readFromFile(argv[2]);

    if (A == NULL) return -1;
    if (b == NULL) return -2;


    printToScreen(A);
    printToScreen(b);

    //gdy niezgodne liczby wierszy
    if (A->r != b->r) {
        fprintf(stderr, "błąd: liczba wierszy macierzy A (%d) nie zgadza się z liczbą wierszy wektora b (%d).\n", A->r, b->r);
        freeMatrix(A);
        freeMatrix(b);
        return 1;  
    }
    // wywołanie eliminacji Gaussa która obejmuje również podstawienie wsteczne
    res = eliminate(A, b);

    if (res == 0) {
        // po eliminacji Gaussa wyniki są zapisane w wektorze b
        printToScreen(b);  // wypisanie rozwiązania z wektora b
    } else {
        fprintf(stderr, "błąd podczas eliminacji gaussa!\n");
    }

    freeMatrix(A);
    freeMatrix(b);

    return 0;
}
