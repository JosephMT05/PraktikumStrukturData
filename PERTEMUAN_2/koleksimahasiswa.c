#ifndef koleksimahasiswa_c
#define koleksimahasiswa_c
#include "koleksimahasiswa.h"

/* Program   : koleksimahasiswa.c */
/* Deskripsi : Realisasi modul ADT Koleksi Mahasiswa */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja */
/* Tanggal   : 4 September 2026*/

void createKoleksiMahasiswa(KoleksiMahasiswa *K){
    // KAMUS
    int i;

    // ALGORITMA
    K->size = 0;
    for (i = 1; i <= 50; i++){
        createMahasiswa(&K->mahasiswa[i]);
    }
};

int getSize(KoleksiMahasiswa K){
    return K.size;
}

int getSizeMaximum(KoleksiMahasiswa K){
    return 50;
};

int getSizeMinimum(KoleksiMahasiswa K){
    return 0;
};

boolean isEmptyKM(KoleksiMahasiswa K){
    return (getSize(K) == 0);
};

boolean isFullKM(KoleksiMahasiswa K){
    return (getSize(K) == 50);
};

void searchXKM(KoleksiMahasiswa K, Mahasiswa m, int *pos){
    // KAMUS
    boolean ketemu;
    int i;

    // ALGORITMA
    ketemu = false;
    *pos = -999;
    for (i = 1; i <= getSize(K); i++){
        if ((getNIM(K.mahasiswa[i]) == getNIM(m)) && (ketemu == false)){
            *pos = i;
            ketemu = true;
        }
    }
};

void addXKM(KoleksiMahasiswa *K, Mahasiswa m){
    if (!isFullKM(*K)){
        K->size++;
        K->mahasiswa[K->size] = m;
    }
};

void addUniqueXKM(KoleksiMahasiswa *K, Mahasiswa m){
    // KAMUS
    int pos;

    // ALGORITMA
    searchXKM(*K, m, &pos);
    if ((pos == -999) && (!isFullKM(*K))){
        addXKM(K, m);
    }
};

void printKM(KoleksiMahasiswa K){
    // KAMUS
    int i;

    // ALGORITMA
    for (i = 1; i <= 50; i++){
        printMahasiswa(K.mahasiswa[i]);
        printf("\n");
    }
};

void viewKM(KoleksiMahasiswa K){
    // KAMUS
    int i;

    // ALGORITMA
    for (i = 1; i <= getSize(K); i++){
        if (!isEmptyKM(K)){
            printMahasiswa(K.mahasiswa[i]);
            printf("\n");
        }
    }
};

int jumlahMhsLulus(KoleksiMahasiswa K){
    // KAMUS
    int i;
    int jumlah;

    // ALGORITMA
    jumlah = 0;
    for (i = 1; i <= getSize(K); i++){
        if (K.mahasiswa[i].NilaiAkhir >= 60){
            jumlah++;
        }
    }
    return jumlah;
};

Mahasiswa MhsNATertinggi(KoleksiMahasiswa K){
    // KAMUS
    Mahasiswa mhs;
    int i;
    int max;

    // ALGORITMA
    createMahasiswa(&mhs);
    max = 0;
    for (i = 1; i <= getSize(K); i++){
        if (K.mahasiswa[i].NilaiAkhir > max){
            max = K.mahasiswa[i].NilaiAkhir;
            mhs = K.mahasiswa[i];
        }
    }
    return mhs;
};

float rataRataNilaiAkhir(KoleksiMahasiswa K){
    // KAMUS
    int i;
    int total;
    float rata;

    // ALGORITMA
    total = 0;
    for (i = 1; i <= getSize(K); i++){
        total += K.mahasiswa[i].NilaiAkhir;
    }
    rata = (float)total / getSize(K);
    return rata;
};

#endif