#include "gauss.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    int res;
    Matrix * A = readFromFile(argv[1]);
    Matrix * b = readFromFile(argv[2]);
    Matrix * x;

    if (A == NULL) return -1;
    if (b == NULL) return -2;
    printToScreen(A);
    printToScreen(b);

    // Wywołanie eliminacji Gaussa, która obejmuje również podstawienie wsteczne
    res = eliminate(A, b);

    if (res == 0) {
        // Utworzenie i wyświetlenie wektora wynikowego x
        x = createMatrix(b->r, 1);
        if (x != NULL) {
            for (int i = 0; i < b->r; i++) {
                x->data[i][0] = b->data[i][0];  // Zapisz rozwiązanie do x
            }
            printToScreen(x);
            freeMatrix(x);
        } else {
            fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
        }
    } else {
        fprintf(stderr, "Błąd podczas eliminacji Gaussa!\n");
    }

    freeMatrix(A);
    freeMatrix(b);

    return 0;
}
