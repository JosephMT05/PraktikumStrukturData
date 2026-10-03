/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060125140145/Joseph Marco Tanuwidjaja*/
/* Tanggal   : 9 September 2026*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

void initMatriks(Matriks *M) {
    /*kamus*/
    int i,j;
    /*algoritma*/
    for (i=1; i<=10; i++) {
        for (j=1; j<=10; j++) {
            M->cell[i][j] = -999;
        }
    }
    M->nbaris = 0;
    M->nkolom = 0;
}

int getNBaris(Matriks M) {
    return M.nbaris;
}

int getNKolom(Matriks M) {
    return M.nkolom;
}

boolean isEmptyMatriks(Matriks M) {
    return (M.nbaris == 0 && M.nkolom == 0);
}

boolean isFullMatriks(Matriks M) {
    return (M.nbaris == 10 && M.nkolom == 10);
}

void addX (Matriks *M, int X, int row, int col) {
    if (!isFullMatriks(*M)) {
        M->cell[row][col] = X;
        if (row > M->nbaris) {
            M->nbaris = row;
        }
        if (col > M->nkolom) {
            M->nkolom = col;
        }
    }
}

void delX (Matriks *M, int X) {
    int i, j;
    for (i = 1; i <= M->nbaris; i++) {
        for (j = 1; j <= M->nkolom; j++) {
            if (M->cell[i][j] == X) {
                M->cell[i][j] = -999; 
            }
        }
    }
}

void isiMatriksRandom(Matriks *M, int x, int y) {
    /*kamus*/
    int i, j;
    /*algoritma*/
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            M->cell[i][j] = rand() % 100; 
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

void isiMatriksIdentitas(Matriks *M, int n) {
    /*kamus*/
    int i, j;
    /*algoritma*/
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                M->cell[i][j] = 1;  
            } else {
                M->cell[i][j] = 0; 
            }
        }
    }
    M->nbaris = n;
    M->nkolom = n;
}

void populateMatriks(Matriks *M, int x, int y) {
    /*kamus*/
    int i, j;
    /*algoritma*/
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("Masukkan elemen M[%d][%d]: ", i, j);
            scanf("%d", &M->cell[i][j]);
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

void printMatriks(Matriks M) {
    /*kamus*/
    int i, j;
    /*algoritma*/
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

void viewMatriks (Matriks M) {
    /*kamus*/
    int i, j;
    /*algoritma*/
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            if (M.cell[i][j] != -999) {
                printf("%d ", M.cell[i][j]);
            } else {
                printf("X "); 
            }
        }
        printf("\n");
    }
}

Matriks addMatriks(Matriks M1, Matriks M2) {
    Matriks M3;
    initMatriks(&M3);
    int i, j;
    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M1.nkolom; j++) {
            M3.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
        }
    }
    M3.nbaris = M1.nbaris;
    M3.nkolom = M1.nkolom;
    return M3;
}

Matriks subMatriks(Matriks M1, Matriks M2) {
    Matriks M3;
    initMatriks(&M3);
    int i, j;
    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M1.nkolom; j++) {
            M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
        }
    }
    M3.nbaris = M1.nbaris;
    M3.nkolom = M1.nkolom;
    return M3;
}

Matriks kaliMatriks(Matriks M1, Matriks M2) {
    Matriks M3;
    initMatriks(&M3);
    int i, j, k;
    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            M3.cell[i][j] = 0;
            for (k = 1; k <= M1.nkolom; k++) {
                M3.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
            }
        }
    }
    M3.nbaris = M1.nbaris;
    M3.nkolom = M2.nkolom;
    return M3;
}

Matriks kaliSkalarMatriks(Matriks M1, int x) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M1.nkolom; j++) {
            M2.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    M2.nbaris = M1.nbaris;
    M2.nkolom = M1.nkolom;
    return M2;
}

void transposeMatriks(Matriks *M) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M->nbaris; i++) {
        for (j = 1; j <= M->nkolom; j++) {
            M2.cell[j][i] = M->cell[i][j];
        }
    }
    M2.nbaris = M->nkolom;
    M2.nkolom = M->nbaris;
    *M = M2; 
}

Matriks getTransposeMatriks(Matriks M) {
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            M.cell[j][i] = M.cell[i][j];
        }
    }
    M.nbaris = M.nkolom;
    M.nkolom = M.nbaris;
    return M;
}

Matriks thresholding(Matriks M, int T) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            if (M.cell[i][j] < T) {
                M2.cell[i][j] = 1; 
            } else {
                M2.cell[i][j] = 255; 
            }
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks citraNegatif(Matriks M) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            M2.cell[i][j] = 255 - M.cell[i][j]; 
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks brightness(Matriks M, int b) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            int nilai = M.cell[i][j] + b;
            if (nilai > 255) {
                nilai = 255; 
            } else if (nilai < 0) {
                nilai = 0; 
            }
            M2.cell[i][j] = nilai;
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks grayscale(Matriks R, Matriks G, Matriks B) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= R.nbaris; i++) {
        for (j = 1; j <= R.nkolom; j++) {
            M2.cell[i][j] = (0.299 * R.cell[i][j] + 
                            0.587 * G.cell[i][j] + 
                            0.114 * B.cell[i][j]);
        }
    }
    M2.nbaris = R.nbaris;
    M2.nkolom = R.nkolom;
    return M2;
}

Matriks translasi(Matriks M, int m, int n) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            int barisbaru = i + m;
            int kolombaru = j + n;
            if (barisbaru >= 1 && barisbaru <= M.nbaris && 
                kolombaru >= 1 && kolombaru <= M.nkolom) {
                M2.cell[i][j] = M.cell[barisbaru][kolombaru];
            } else {
                M2.cell[i][j] = 0; 
            }
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks flipHorizontal(Matriks M) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            M2.cell[i][j] = M.cell[i][M.nkolom - j + 1]; 
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks flipVertical(Matriks M) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            M2.cell[i][j] = M.cell[M.nbaris - i + 1][j]; 
        }
    }
    M2.nbaris = M.nbaris;
    M2.nkolom = M.nkolom;
    return M2;
}

Matriks addPadding(Matriks M, int n) {
    Matriks M2;
    initMatriks(&M2);
    int i, j;

    M2.nbaris = M.nbaris + 2 * n;
    M2.nkolom = M.nkolom + 2 * n;

    for (i = 1; i <= M2.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            if (i > n && i <= M.nbaris + n && 
                j > n && j <= M.nkolom + n) {
                M2.cell[i][j] = M.cell[i - n][j - n]; 
            } else {
                M2.cell[i][j] = 0; 
            }
        }
    }
    return M2;
}

Matriks maxPooling(Matriks M, int size) {
    Matriks M2;
    initMatriks(&M2);
    int i, j, m, n;
    int newRow, newCol;

    M2.nbaris = M.nbaris / size;  
    M2.nkolom = M.nkolom / size; 
    
    for (i = 1; i <= M2.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            newRow = (i - 1) * size + 1;
            newCol = (j - 1) * size + 1;
            int maxVal = M.cell[newRow][newCol]; 
            
            for (m = 0; m < size ; m++) {
                for (n = 0; n < size ; n++) {
                    if (M.cell[newRow + m][newCol + n] > maxVal) {
                        maxVal = M.cell[newRow + m][newCol + n];
                    }
                }
            }
            M2.cell[i][j] = maxVal;
        }
    }
    return M2;
}

Matriks avgPooling(Matriks M, int size) {
    Matriks M2;
    initMatriks(&M2);
    int i, j, m, n;
    int newRow, newCol;
    
    M2.nbaris = M.nbaris / size;  
    M2.nkolom = M.nkolom / size; 

    for (i = 1; i <= M2.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            newRow = (i - 1) * size + 1;
            newCol = (j - 1) * size + 1;
            int count = 0;
            
            for (m = 0; m < size ; m++) {
                for (n = 0; n < size ; n++) {
                    count += M.cell[newRow + m][newCol + n];
                }
            }
            M2.cell[i][j] = count / (size * size); 
        }
    }
    return M2;
}

Matriks conv(Matriks M, Matriks K) {
    Matriks M2;
    initMatriks(&M2);
    int i, j, m, n;
    
    M2.nbaris = M.nbaris - K.nbaris + 1;  
    M2.nkolom = M.nkolom - K.nkolom + 1;  

    for (i = 1; i <= M2.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            int sumVal = 0;
            
            for (m = 1; m <= K.nbaris; m++) {
                for (n = 1; n <= K.nkolom; n++) {
                    sumVal += M.cell[i + m - 1][j + n - 1] * K.cell[m][n];
                }
            }
            M2.cell[i][j] = sumVal;
        }
    }
    return M2;
}