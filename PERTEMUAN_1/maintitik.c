/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060125140145 - Joseph Marco Tanuwidjaja*/
/* Tanggal   : 26 Agustus 2026*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik T1;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&T1,4,5);
	printf("Nilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));
	printf("\nKuadran = %d",kuadran(T1));
	printf("\nApakah titik berada di sumbu X? %d",isOnSumbuX(T1));
	printf("\nApakah titik berada di sumbu Y? %d",isOnSumbuY(T1));
	printf("\nApakah titik berada di titik asal? %d",isOrigin(T1));
	printf("\nDilatasi dengan k=2");
	dilatasi(&T1, 2);
	printf("\nNilai absis setelah dilatasi = %d",getAbsis(T1));
	printf("\nNilai ordinat setelah dilatasi = %d",getOrdinat(T1));
	printf("\n");
	
	return 0;
}