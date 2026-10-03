#ifndef MAHASISWA_H
#define MAHASISWA_H

/* Program   : mahasiswa.h */
/* Deskripsi : Header modul ADT Mahasiswa */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja */
/* Tanggal   : 4 September 2026*/

#include <stdio.h>
#include "boolean.h"

/* type Mahasiswa = < NIM: string, Nama: string, Tugas: integer,
                      Kuis: integer, UTS: integer, UAS: integer, 
                      NilaiAkhir: integer, NilaiHuruf: char >*/

typedef struct{
    int NIM;
    char Nama[50];
    int Tugas;
    int Kuis;
    int UTS;
    int UAS;
    int NilaiAkhir;
    char NilaiHuruf;
} Mahasiswa;

/************************KONSTRUKTOR*************************/
/* procedure createMahasiswa(Output M: Mahasiswa)
    {I.S.: -}
    {F.S.: mengembalikan Mahasiswa dengan semua elemen berisi kosong atau default}
    {Proses: menginisialisasi M} */
void createMahasiswa(Mahasiswa *M);

/************************SELEKTOR*************************/
/* function getNIM(M: Mahasiswa) -> integer
    {mengembalikan NIM mahasiswa} */
int getNIM(Mahasiswa M);

/* function getNama(M: Mahasiswa) -> integer
    {mengembalikan nama mahasiswa} */
char *getNama(Mahasiswa *M);

/* function getTugas(M: Mahasiswa) -> integer
    {mengembalikan nilai tugas mahasiswa} */
int getTugas(Mahasiswa M);

/* function getKuis(M: Mahasiswa) -> integer
    {mengembalikan nilai kuis mahasiswa} */
int getKuis(Mahasiswa M);

/* function getUTS(M: Mahasiswa) -> integer
    {mengembalikan nilai UTS mahasiswa} */
int getUTS(Mahasiswa M);

/* function getUAS(M: Mahasiswa) -> integer
    {mengembalikan nilai UAS mahasiswa} */
int getUAS(Mahasiswa M);

/* function getNilaiAkhir(M: Mahasiswa) -> integer
    {mengembalikan nilai akhir mahasiswa} */
int getNilaiAkhir(Mahasiswa M);

/* function getNilaiHuruf(M: Mahasiswa) -> character
    {mengembalikan nilai huruf mahasiswa} */
char getNilaiHuruf(Mahasiswa M);

/*************************MUTATOR*************************/
/* procedure setNIM(M: Mahasiswa, NIM: integer)
    {mengatur NIM mahasiswa} */
void setNIM(Mahasiswa *M, int NIM);

/* procedure setNama(M: Mahasiswa, Nama: character)
    {mengatur nama mahasiswa} */
void setNama(Mahasiswa *M, char *Nama);

/* procedure setTugas(M: Mahasiswa, Tugas: integer)
    {mengatur nilai tugas mahasiswa} */
void setTugas(Mahasiswa *M, int Tugas);

/* procedure setKuis(M: Mahasiswa, Kuis: integer)
    {mengatur nilai kuis mahasiswa} */
void setKuis(Mahasiswa *M, int Kuis);

/* procedure setUTS(M: Mahasiswa, UTS: integer)
    {mengatur nilai UTS mahasiswa} */
void setUTS(Mahasiswa *M, int UTS);

/* procedure setUAS(M: Mahasiswa, UAS: integer)
    {mengatur nilai UAS mahasiswa} */
void setUAS(Mahasiswa *M, int UAS);

/* procedure getNilaiAkhir(M: Mahasiswa) -> integer
    {mengatur nilai akhir mahasiswa} */
void setNilaiAkhir(Mahasiswa *M, int NilaiAkhir);

/* prodecure getNilaiHuruf(M: Mahasiswa) -> character
    {mengatur nilai huruf mahasiswa} */
void setNilaiHuruf(Mahasiswa *M, char NilaiHuruf);

/*************************OPERASI BACA/TULIS*************************/
/* procedure printMahasiswa(input M:Mahasiswa)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen M ke layar} */
void printMahasiswa(Mahasiswa M);

/*************************OPERASI STATISTIK*************************/
/*function HitungNilaiAkhir(M:Mahasiswa) -> integer
    {mengembalikan hasil nilai akhir mahasiswa} */
int HitungNilaiAkhir(Mahasiswa M);

/*function KonversiNilaiAkhir(M:Mahasiswa) -> integer
    {mengonversi hasil nilai akhir mahasiswa ke huruf} 
    Asumsi: nilai akhir sudah ada di mahasiswa */
char KonversiNilaiAkhir(Mahasiswa M);

#endif