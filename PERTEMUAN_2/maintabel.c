#include <stdio.h>
#include "tabel.h"

/* Deskripsi : Aplikasi tabel.c*/
/* NIM/Nama : Joseph Marco Tanuwidjaja*/
/* Tanggal : 2 September 2026*/

int main() {
    Tabel T;
    createTable(&T);
    addXTable(&T, 'A');
    addXTable(&T, 'B');
    addXTable(&T, 'C');
    addXTable(&T, 'A');
    addXTable(&T, 'D');
    addXTable(&T, 'E');
    addXTable(&T, 'A');
    addXTable(&T, 'F');
    addXTable(&T, 'G');
    addXTable(&T, 'H');
    printTable(T);
    printf("Ukuran tabel: %d\n", getSize(T));
    printf("Modus: %c\n", Modus(T));
    return 0;
}