#include "koleksimahasiswa.h"
#include <stdio.h>

/* Program   : mainkoleksimahasiswa.c */
/* Deskripsi : Aplikasi modul ADT Koleksi Mahasiswa */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja */
/* Tanggal   : 4 September 2026*/

int main(){
    // KAMUS
    KoleksiMahasiswa K;
    Mahasiswa m1;
    Mahasiswa m2;
    Mahasiswa m3;
    Mahasiswa m4;
    Mahasiswa m5;
    Mahasiswa msementara;
    int pos;

    // ALGORITMA
    printf("Ini adalah driver modul KoleksiMahasiswa \n");
    setNIM(&m1, 250001);
    setNIM(&m2, 250002);
    setNIM(&m3, 250003);
    setNIM(&m4, 250004);
    setNIM(&m5, 250005);
    setNama(&m1, "Joseph");
    setNama(&m2, "Marco");
    setNama(&m3, "Tanuwidjaja");
    setNama(&m4, "Joseph Marco Tanuwidjaja");
    setNama(&m5, "Joseph M. Tanuwidjaja");
    setTugas(&m1, 93);
    setTugas(&m2, 86);
    setTugas(&m3, 74);
    setTugas(&m4, 82);
    setTugas(&m5, 65);
    setKuis(&m1, 88);
    setKuis(&m2, 92);
    setKuis(&m3, 79);
    setKuis(&m4, 85);
    setKuis(&m5, 70);
    setUTS(&m1, 90);
    setUTS(&m2, 84);
    setUTS(&m3, 76);
    setUTS(&m4, 88);
    setUTS(&m5, 72);
    setUAS(&m1, 95);
    setUAS(&m2, 89);
    setUAS(&m3, 80);
    setUAS(&m4, 92);
    setUAS(&m5, 75);
    setNilaiAkhir(&m1, HitungNilaiAkhir(m1));
    setNilaiAkhir(&m2, HitungNilaiAkhir(m2));
    setNilaiAkhir(&m3, HitungNilaiAkhir(m3));
    setNilaiAkhir(&m4, HitungNilaiAkhir(m4));
    setNilaiAkhir(&m5, HitungNilaiAkhir(m5));
    setNilaiHuruf(&m1, KonversiNilaiAkhir(m1));
    setNilaiHuruf(&m2, KonversiNilaiAkhir(m2));
    setNilaiHuruf(&m3, KonversiNilaiAkhir(m3));
    setNilaiHuruf(&m4, KonversiNilaiAkhir(m4));
    setNilaiHuruf(&m5, KonversiNilaiAkhir(m5));
    createKoleksiMahasiswa(&K);
    addXKM(&K, m1);
    addXKM(&K, m2);
    addXKM(&K, m3);
    addXKM(&K, m4);
    addXKM(&K, m5);
    printf("Daftar mahasiswa:\n");
    viewKM(K);
    printf("Jumlah mahasiswa yang lulus: %d\n", jumlahMhsLulus(K));
}