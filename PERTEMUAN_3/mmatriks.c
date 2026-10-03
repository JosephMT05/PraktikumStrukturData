/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060125140145/Joseph Marco Tanuwidjaja */
/* Tanggal   : 9 September 2026 */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main() {
	// Kamus
	Matriks M1, M2, M3;

	// Algoritma
	printf("\n");
	printf("Halo, ini adalah modul aplikasi ADT matriks\n");
	printf("\n");
	initMatriks(&M1);
	isiMatriksRandom(&M1, 5, 5);
	printf("Matriks M1:\n");
	printMatriks(M1);
	printf("Jumlah baris M1: %d\n", getNBaris(M1));
	printf("Jumlah kolom M1: %d\n", getNKolom(M1));
	printf("Apakah M1 kosong? %s\n", isEmptyMatriks(M1) ? "Ya" : "Tidak");
	printf("Apakah M1 penuh? %s\n", isFullMatriks(M1) ? "Ya" : "Tidak");
	printf("\n");
	addX(&M1, 99, 3, 3);
	printf("Matriks M1 setelah menambahkan 99 di posisi (3,3):\n");
	printMatriks(M1);
	printf("\n");
	delX(&M1, 99);
	printf("Matriks M1 setelah menghapus 99:\n");
	printMatriks(M1);
	addX(&M1, 90, 3, 3);
	printf("\n");
	printf("Matriks M1:\n");
	printMatriks(M1);
	printf("\n");
	initMatriks(&M2);
	isiMatriksIdentitas(&M2, 5);
	printf("Matriks M2 (Identitas):\n");
	printMatriks(M2);
	printf("\n");
	initMatriks(&M3);
	isiMatriksRandom(&M3, 5, 5);
	printf("Matriks M3:\n");
	printMatriks(M3);
	printf("\n");
	printf("Operasi Aritmatika:\n");
	printf("\n");
	Matriks M4 = addMatriks(M1, M2);
	printf("Hasil penjumlahan M1 + M2:\n");
	printMatriks(M4);
	printf("\n");
	Matriks M5 = subMatriks(M1, M2);
	printf("Hasil pengurangan M1 - M2:\n");
	printMatriks(M5);
	printf("\n");
	Matriks M6 = kaliMatriks(M1, M3);
	printf("Hasil perkalian M1 * M3:\n");
	printMatriks(M6);
	printf("\n");
	Matriks M7 = kaliSkalarMatriks(M1, 2);
	printf("Hasil perkalian M1 dengan skalar 2:\n");
	printMatriks(M7);
	printf("\n");
	printf("Operasi Lainnya:\n");
	printf("\n");
	printf("Matriks M1 sebelum transpose:\n");
	printMatriks(M1);
	printf("\n");
	transposeMatriks(&M1);
	printf("Matriks M1 setelah transpose:\n");
	printMatriks(M1);
	printf("\n");
	getTransposeMatriks(M1);
	printf("Matriks M1 setelah getTransposeMatriks:\n");
	printMatriks(M1);
	printf("\n");
	printf("Operasi Matriks untuk Image Processing:\n");
	printf("\n");
	Matriks M8 = thresholding(M1, 128);
	printf("Matriks M1 setelah thresholding dengan T=128(Matriks M8):\n");
	printMatriks(M8);
	printf("\n");
	Matriks M9 = citraNegatif(M1);
	printf("Matriks M1 setelah citra negatif(Matriks M9):\n");
	printMatriks(M9);
	printf("\n");
	Matriks M10 = brightness(M1, 50);
	printf("Matriks M1 setelah brightness +50(Matriks M10):\n");
	printMatriks(M10);
	printf("\n");
	Matriks M11 = grayscale(M1, M2, M3);
	printf("Matriks M1 setelah grayscale dengan M2 dan M3(Matriks M11):\n");
	printMatriks(M11);
	printf("\n");
	Matriks M12 = translasi(M1, 1, 1);
	printf("Matriks M1 setelah translasi (1,1)(Matriks M12):\n");
	printMatriks(M12);
	printf("\n");
	Matriks M13 = flipHorizontal(M1);
	printf("Matriks M1 setelah flip horizontal(Matriks M13):\n");
	printMatriks(M13);
	printf("\n");
	Matriks M14 = flipVertical(M1);
	printf("Matriks M1 setelah flip vertical(Matriks M14):\n");
	printMatriks(M14);
	printf("\n");
	Matriks M15 = addPadding(M1, 2);
	printf("Matriks M1 setelah add padding 2(Matriks M15):\n");
	printMatriks(M15);
	printf("\n");
	Matriks M16 = maxPooling(M1, 2);
	printf("Matriks M1 setelah max pooling 2x2(Matriks M16):\n");
	printMatriks(M16);
	printf("\n");
	Matriks M17 = avgPooling(M1, 2);
	printf("Matriks M1 setelah average pooling 2x2(Matriks M17):\n");
	printMatriks(M17);
	printf("\n");
	Matriks M18 = conv(M1, M3);
	printf("Matriks M1 setelah konvolusi dengan M3(Matriks M18):\n");
	printMatriks(M18);
	return 0;
}
