/***********************************/
/* Program   : garis.h */
/* Deskripsi : header file modul Garis */
/* NIM/Nama  : 24060125140145 - Joseph Marco Tanuwidjaja*/
/* Tanggal   : 30 Agustus 2026*/
/***********************************/
#include "titik.h"
#include <stdio.h>

#ifndef garis_H
#define garis_H 


/* NOTASI ALGORITMIK : */
/* type Garis = <P1:Titik, P2:Titik> */
/* DITERJEMAHKAN KE BAHASA C : */
typedef struct {Titik TitikAwal; Titik TitikAkhir;} Garis;
/* cara akses G:Garis, G.TitikAwal, G.TitikAkhir */

/*KONSTRUKTOR*/
/* procedure makeGaris0(output G:Garis) */
/* {I.S.: -} */
/* {F.S.: G terdefinisi, TitikAwal=(0,0), TitikAkhir=(1,1)} */
/* {proses: menginisialisasi titik awal dengan (0,0) dan titik akhir dengan (1,1)} */
void makeGaris0(Garis *G);

/* procedure makeGaris(output G:Garis, input Awal:Titik, Akhir:Titik) */
/* {I.S.: Awal dan Akhir terdefinisi} */
/* {F.S.: G terdefinisi, TitikAwal=Awal, TitikAkhir=Akhir} */
/* {proses: mengisi komponen TitikAwal dengan Awal dan TitikAkhir dengan Akhir} */
void makeGaris(Garis *G, Titik T1, Titik T2);

/**********SELEKTOR**********/
/* function getTitikAwal(G:Garis)->Titik */
/* {mengembalikan nilai komponen TitikAwal dari G} */
Titik getTitikAwal(Garis G);

/* function getTitikAkhir(G:Garis)->Titik */
/* {mengembalikan nilai komponen TitikAkhir dari G} */
Titik getTitikAkhir(Garis G);

/*********MUTATOR**********/
/* procedure setTitikAwal(input/output G:Garis, input T:Titik) */
/* {I.S.: G terdefinisi} */
/* {F.S.: G.TitikAwal=T} */
/* {proses: mengubah nilai komponen TitikAwal G dengan T} */
void setTitikAwal(Garis *G, Titik T);
 
/* procedure setTitikAkhir(input/output G:Garis, input T:Titik) */
/* {I.S.: G terdefinisi} */
/* {F.S.: G.TitikAkhir=T} */
/* {proses: mengubah nilai komponen TitikAkhir G dengan T} */
void setTitikAkhir(Garis *G, Titik T);


/*********OPERASI**********/
/* procedure tampilGaris(input G:Garis) */
/* {I.S.: G terdefinisi} */
/* {F.S.: komponen G tercetak ke layar} */
/* {proses: menampilkan nilai TitikAwal dan TitikAkhir G ke layar} */
void tampilGaris(Garis G);

/* function panjangGaris(G:Garis)->float */
/* {I.S.: G terdefinisi} */
/* {F.S.: mengembalikan panjang garis G} */
/* {proses: menghitung jarak Euclidean antara TitikAwal dan TitikAkhir} */
float panjangGaris(Garis G);

/* function gradienGaris(G:Garis)->float */
/* {I.S.: G terdefinisi, garis tidak vertikal (dx != 0)} */
/* {F.S.: mengembalikan gradien (kemiringan) garis G} */
/* {proses: menghitung m = (y2-y1)/(x2-x1)} */
float gradienGaris(Garis G);

/* function isSejajar(G1:Garis, G2:Garis)->boolean */
/* {I.S.: G1 dan G2 terdefinisi} */
/* {F.S.: mengembalikan true jika G1 sejajar G2, false jika sebaliknya} */
/* {proses: membandingkan gradien G1 dan G2} */
boolean isSejajar(Garis G1, Garis G2);

/* function isTegakLurus(G1:Garis, G2:Garis)->boolean */
/* {I.S.: G1 dan G2 terdefinisi} */
/* {F.S.: mengembalikan true jika G1 tegak lurus G2, false jika sebaliknya} */
/* {proses: mengecek apakah hasil kali gradien G1 dan G2 = -1} */
boolean isTegakLurus(Garis G1, Garis G2);

/* procedure tampilPersamaanGaris(input G:Garis) */
/* {I.S.: G terdefinisi} */
/* {F.S.: persamaan garis G tercetak ke layar dalam bentuk y=mx+c} */
/* {proses: menghitung gradien m dan konstanta c lalu menampilkannya} */
void tampilPersamaanGaris(Garis G);

/* function titikTengahGaris(G:Garis)->Titik */
/* {I.S.: G terdefinisi} */
/* {F.S.: mengembalikan Titik tengah dari garis G} */
/* {proses: menghitung titik tengah antara TitikAwal dan TitikAkhir} */
Titik titikTengahGaris(Garis G);


#endif