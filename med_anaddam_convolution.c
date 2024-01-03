#include <stdio.h>
#include <stdlib.h>
// Med ANADDAM , II-CCN with pride !

// Fonction pour allouer dynamiquement une matrice carrée de taille N
int** get_random_matrice(int N) {
    int** matrice = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrice[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            matrice[i][j] = rand() % 100; // Valeurs aléatoires entre 0 et 99
        }
    }
    return matrice;
}

// Fonction pour calculer et retourner la trace d'une matrice carrée
int trace_matrice(int** matrice, int N) {
    int trace = 0;
    for (int i = 0; i < N; i++) {
        trace += matrice[i][i];
    }
    return trace;
}

// Fonction pour calculer et retourner le produit de convolution de A par B
int conv_matrices(int** A, int** B, int N, int p) {
    int result = 0;
    for (int i = p; i < N - p; i++) {
        for (int j = p; j < N - p; j++) {
            for (int k = -p; k <= p; k++) {
                for (int l = -p; l <= p; l++) {
                    result += A[i + k][j + l] * B[k + p][l + p];
                }
            }
        }
    }
    return result;
}

// Fonction pour libérer la mémoire allouée pour une matrice carrée
void free_matrice(int** matrice, int N) {
    for (int i = 0; i < N; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

int main() {
    int N = 5; // Exemple de taille de la matrice carrée
    int p = 1; // Exemple de taille du filtre de convolution (2p+1)

    // Création et affichage d'une matrice carrée aléatoire
    int** matriceA = get_random_matrice(N);
    printf("Matrice A :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriceA[i][j]);
        }
        printf("\n");
    }

    // Calcul et affichage de la trace de la matrice carrée
    int trace = trace_matrice(matriceA, N);
    printf("Trace de la matrice A : %d\n", trace);

    // Création et affichage d'une matrice de filtre de convolution
    int** matriceB = get_random_matrice(2 * p + 1);
    printf("\nMatrice B (filtre de convolution) :\n");
    for (int i = 0; i < 2 * p + 1; i++) {
        for (int j = 0; j < 2 * p + 1; j++) {
            printf("%d ", matriceB[i][j]);
        }
        printf("\n");
    }

    // Calcul et affichage du produit de convolution de A par B
    int convolutionResult = conv_matrices(matriceA, matriceB, N, p);
    printf("\nRésultat du produit de convolution : %d\n", convolutionResult);

    // Libération de la mémoire
    free_matrice(matriceA, N);
    free_matrice(matriceB, 2 * p + 1);

    return 0;
}
