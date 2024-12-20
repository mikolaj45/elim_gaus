#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r; // liczba wierszy macierzy

    for (int k = 0; k < n; k++) {
        // znajdowanie maksymalnego elementu w kolumnie do przestawiania
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k])) {
                maxRow = i;
            }
        }

        // zamiana wierszy w macierzy mat i wektorze b
        if (maxRow != k) {
            double *tempaaaRow = mat->data[k];
            mat->data[k] = mat->data[maxRow];
            mat->data[maxRow] = tempaaaRow;

            double tempB = b->data[k][0];
            b->data[k][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tempB;
        }

        // sprawdzanie czy dzielenie przez 0 nie wystąpi
        if (fabs(mat->data[k][k]) < 1e-9) {
            return 1; // Macierz osobliwa
        }

        // Normalizacja bieżącego wiersza
        double diagElement = mat->data[k][k];
        for (int j = k; j < n; j++) {
            mat->data[k][j] /= diagElement;
        }
        b->data[k][0] /= diagElement;

        // zerowanie elementów poniżej bieżącego wiersza
        for (int i = k + 1; i < n; i++) {
            double factor = mat->data[i][k];

            for (int j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }

            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    
    for (int k = n - 1; k >= 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            double factor = mat->data[i][k];

            for (int j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }

            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0; 
}

