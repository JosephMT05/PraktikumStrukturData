/***********************************/
/* Program   : mgaris.c */
/* Deskripsi : aplikasi driver modul Garis */
/* NIM/Nama  : 24060125140145 - Joseph Marco Tanuwidjaja*/
/* Tanggal   : 30 Agustus 2026*/
/***********************************/

#include "garis.h"
#include <stdio.h>

int main() {
    //kamus main
    Garis G1;
    Titik T1, T2;

    //algoritma
    printf("Halo, ini driver modul Garis \n");
    makeTitik(&T1, 2, 3);
    makeTitik(&T2, 5, 7);
    makeGaris(&G1, T1, T2);

    tampilGaris(G1);
    printf("Panjang garis = %.2f\n", panjangGaris(G1));
    printf("Gradien garis = %.2f\n", gradienGaris(G1));
    tampilPersamaanGaris(G1);
    
    Titik tengah = titikTengahGaris(G1);
    printf("Titik tengah garis = (%d, %d)\n", getAbsis(tengah), getOrdinat(tengah));

    return 0;
}