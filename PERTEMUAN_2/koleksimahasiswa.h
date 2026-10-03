#ifndef KOLEKSIMAHASISWA_H
#define KOLEKSIMAHASISWA_H
#include <stdio.h>
#include "boolean.h"
#include "mahasiswa.h"

/* Program   : koleksimahasiswa.h */
/* Deskripsi : Header modul ADT Koleksi Mahasiswa */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja */
/* Tanggal   : 4 September 2026*/

/* type KoleksiMahasiswa = < mahasiswa: array [1 .. 50] of Mahasiswa,
                             size: integer >*/

typedef struct{
    Mahasiswa mahasiswa[50];
    int size;
} KoleksiMahasiswa;

/************************KONSTRUKTOR*************************/
/* procedure createKoleksiMahasiswa( output K: KoleksiMahasiswa)
    {I.S.: -}
    {F.S.: mengembalikan KoleksiMahasiswa dengan semua elemen berisi kosong atau default}
    {Proses: menginisialisasi K} */
void createKoleksiMahasiswa(KoleksiMahasiswa *K);

/************************SELEKTOR*************************/

/* function getSize( K: KoleksiMahasiswa) -> integer
    {mengembalikan banyak elemen pengisi K } */
int getSize(KoleksiMahasiswa K);

/* function getSizeMaximum( K: KoleksiMahasiswa) -> integer
    {mengembalikan maksimum banyak elemen pengisi K } */
int getSizeMaximum(KoleksiMahasiswa K);

/* function getSizeMinimum( K: KoleksiMahasiswa) -> integer
    {mengembalikan minimum banyak elemen pengisi K } */
int getSizeMinimum(KoleksiMahasiswa K);

/*************************PREDIKAT*************************/
/* function isEmptyKM( K: KoleksiMahasiswa) -> boolean
    {mengembalikan True jika K kosong } */
boolean isEmptyKM(KoleksiMahasiswa K);

/* function isFullKM( K: KoleksiMahasiswa) -> boolean
    {mengembalikan True jika K penuh } */
boolean isFullKM(KoleksiMahasiswa K);

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchXKM (input K:KoleksiMahasiswa, input m:Mahasiswa, output pos:integer )
    {I.S.: K terdefinisi, m terdefinisi }
    {F.S.: pos berisi posisi ketemu di K.mahasiswa, atau -999 jika tidak ketemu }
    {Proses: mencari elemen bernilai m dalam K.mahasiswa} */
void searchXKM(KoleksiMahasiswa K, Mahasiswa m, int *pos);

/*************************MUTATOR*************************/
/* procedure addXKM (input/output K:KoleksiMahasiswa, input m: Mahasiswa)
    {I.S.: K terdefinisi, m terdefinisi }
    {F.S.: isi K.mahasiswa bertambah 1 elemen jika belum penuh}
    {Proses: mengisi elemen K.mahasiswa dengan nilai m}*/
void addXKM(KoleksiMahasiswa *K, Mahasiswa m);

/* procedure addUniqueXKM (input/output K:KoleksiMahasiswa, input m: Mahasiswa)
    {I.S.: K terdefinisi, m terdefinisi }
    {F.S.: isi K.mahasiswa bertambah 1 elemen jika m unik dan koleksi belum penuh}
    {Proses: mengisi elemen K.mahasiswa dengan nilai unik m}*/
void addUniqueXKM(KoleksiMahasiswa *K, Mahasiswa m);

/*************************OPERASI BACA/TULIS*************************/
/* procedure printKM (input K:KoleksiMahasiswa)
    {I.S.: K terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen K ke layar} */
void printKM(KoleksiMahasiswa K);

/* procedure viewKM (input K:KoleksiMahasiswa)
    {I.S.: K terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen K yang terisi ke layar} */
void viewKM(KoleksiMahasiswa K);

/*************************OPERASI LAINNYA*************************/
/* function jumlahMhsLulus (input K:KoleksiMahasiswa)
    {I.S.: K terdefinisi}
    {F.S.: -}
    {Proses: menghitung dan mengembalikan jumlah mahasiswa yang lulus (minimal mendapat nilai C)} */
int jumlahMhsLulus(KoleksiMahasiswa K);

/* function MhsNATertinggi (input K:KoleksiMahasiswa)
    {I.S.: K terdefinisi}
    {F.S.: -}
    {Proses: mengembalikan mahasiswa dengan nilai tertinggi} */
Mahasiswa MhsNATertinggi(KoleksiMahasiswa K);

/* function rataRataNilaiAkhir (input K:KoleksiMahasiswa)
    {I.S.: K terdefinisi}
    {F.S.: -}
    {Proses: menghitung dan mengembalikan rata-rata nilai akhir mahasiswa dalam koleksi} */
float rataRataNilaiAkhir(KoleksiMahasiswa K);

#endif