/***********************************/
/* Program   : garis.c */
/* Deskripsi : realisasi modul Garis */
/* NIM/Nama  : 24060125140145 - Joseph Marco Tanuwidjaja*/
/* Tanggal   : 30 Agustus 2026*/
/***********************************/

#include "garis.h"
#include <stdio.h>
#include <math.h>

void makeGaris0(Garis *G){
    makeTitik0(&(G->TitikAwal));
    makeTitik(&(G->TitikAkhir), 1, 1);
}

void makeGaris(Garis *G, Titik T1, Titik T2){
    G->TitikAwal = T1;
    G->TitikAkhir = T2;
}

Titik getTitikAwal(Garis G){
    return G.TitikAwal;
}

Titik getTitikAkhir(Garis G){
    return G.TitikAkhir;
}

void setTitikAwal(Garis *G, Titik T){
    G->TitikAwal = T;
}

void setTitikAkhir(Garis *G, Titik T){
    G->TitikAkhir = T;
}

void tampilGaris(Garis G){
    printf("Titik Awal: (%d, %d)\n", getAbsis(getTitikAwal(G)), getOrdinat(getTitikAwal(G)));
    printf("Titik Akhir: (%d, %d)\n", getAbsis(getTitikAkhir(G)), getOrdinat(getTitikAkhir(G)));
}

float panjangGaris(Garis G){
    int dx = getAbsis(getTitikAkhir(G)) - getAbsis(getTitikAwal(G));
    int dy = getOrdinat(getTitikAkhir(G)) - getOrdinat(getTitikAwal(G));
    return sqrt((float)(dx * dx + dy * dy));
}

float gradienGaris(Garis G){
    int dx = getAbsis(getTitikAkhir(G)) - getAbsis(getTitikAwal(G));
    int dy = getOrdinat(getTitikAkhir(G)) - getOrdinat(getTitikAwal(G));
    
    if (dx == 0) {
        printf("Gradien tidak terdefinisi (garis vertikal)\n");
        return 0; 
    }
    else {
        return (float)dy / dx;
    }
}

boolean isSejajar(Garis G1, Garis G2){
    float gradien1 = gradienGaris(G1);
    float gradien2 = gradienGaris(G2);
    
    if (gradien1 == gradien2) {
        return true;
    } else {
        return false;
    }
}

boolean isTegakLurus(Garis G1, Garis G2){
    float gradien1 = gradienGaris(G1);
    float gradien2 = gradienGaris(G2);
    
    if (gradien1 * gradien2 == -1) {
        return true;
    } else {
        return false;
    }
}

void tampilPersamaanGaris(Garis G){
    float m = gradienGaris(G);
    float c = getOrdinat(getTitikAwal(G)) - (m * getAbsis(getTitikAwal(G)));
    printf("Persamaan garis: y = %.2fx + %.2f\n", m, c);
}

Titik titikTengahGaris(Garis G){
    Titik tengah;
    int x_tengah = (getAbsis(getTitikAwal(G)) + getAbsis(getTitikAkhir(G))) / 2;
    int y_tengah = (getOrdinat(getTitikAwal(G)) + getOrdinat(getTitikAkhir(G))) / 2;
    makeTitik(&tengah, x_tengah, y_tengah);
    return tengah;
}