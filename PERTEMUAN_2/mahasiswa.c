#ifndef mahasiswa_c
#define mahasiswa_c
#include "mahasiswa.h"
#include <string.h>

/* Program   : mahasiswa.c */
/* Deskripsi : Realisasi modul ADT Mahasiswa */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja */
/* Tanggal   : 4 September 2026*/

void createMahasiswa(Mahasiswa *M){
    M->NIM = 0;
    M->Nama[0] = ' ';
    M->Tugas = 0;
    M->Kuis = 0;
    M->UTS = 0;
    M->UAS = 0;
    M->NilaiAkhir = 0;
    M->NilaiHuruf = ' ';
};

int getNIM(Mahasiswa M){
    return M.NIM;
};

char *getNama(Mahasiswa *M){
    return M->Nama;
};

int getTugas(Mahasiswa M){
    return M.Tugas;
};

int getKuis(Mahasiswa M){
    return M.Kuis;
};

int getUTS(Mahasiswa M){
    return M.UTS;
};

int getUAS(Mahasiswa M){
    return M.UAS;
};

int getNilaiAkhir(Mahasiswa M){
    return M.NilaiAkhir;
};

char getNilaiHuruf(Mahasiswa M){
    return M.NilaiHuruf;
};

void setNIM(Mahasiswa *M, int NIM){
    M->NIM = NIM;
};

void setNama(Mahasiswa *M, char *Nama){
    strcpy(M->Nama, Nama);
};

void setTugas(Mahasiswa *M, int Tugas){
    M->Tugas = Tugas;
};

void setKuis(Mahasiswa *M, int Kuis){
    M->Kuis = Kuis;
};

void setUTS(Mahasiswa *M, int UTS){
    M->UTS = UTS;
};

void setUAS(Mahasiswa *M, int UAS){
    M->UAS = UAS;
};

void setNilaiAkhir(Mahasiswa *M, int NilaiAkhir){
    M->NilaiAkhir = NilaiAkhir;
};

void setNilaiHuruf(Mahasiswa *M, char NilaiHuruf){
    M->NilaiHuruf = NilaiHuruf;
};

void printMahasiswa(Mahasiswa M){
    printf("NIM: %d\n", getNIM(M));
    printf("Nama: %s\n", getNama(&M));
    printf("Tugas: %d\n", getTugas(M));
    printf("Kuis: %d\n", getKuis(M));
    printf("UTS: %d\n", getUTS(M));
    printf("UAS: %d\n", getUAS(M));
    printf("Nilai Akhir: %d\n", getNilaiAkhir(M));
    printf("Nilai Huruf: %c\n", getNilaiHuruf(M));
};

int HitungNilaiAkhir(Mahasiswa M){
    return (getTugas(M) * 0.2) + (getKuis(M) * 0.1) + (getUTS(M) * 0.3) + (getUAS(M) * 0.4);
};

char KonversiNilaiAkhir(Mahasiswa M){
    // KAMUS
    int nilaiAkhir;

    // ALGORITMA
    nilaiAkhir = getNilaiAkhir(M);
    if (nilaiAkhir >= 80 || nilaiAkhir <= 100){
        return 'A';
    }
    else if (nilaiAkhir >= 70 || nilaiAkhir < 80){
        return 'B';
    }
    else if (nilaiAkhir >= 60 || nilaiAkhir < 70){
        return 'C';
    }
    else if (nilaiAkhir >= 50 || nilaiAkhir < 60){
        return 'D';
    }
    else{
        return 'E';
    }
};
#endif