/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060125140145 - Joseph Marco Tanuwidjaja*/
/* Tanggal   : 26 Agustus 2026*/
/***********************************/
#include <stdio.h>
#include "titik.h"

/* makeTitik */
void makeTitik(Titik *T, int x, int y){
    T->absis = x;
    T->ordinat = y;
}

/* makeTitik0 */
void makeTitik0(Titik *T){
    T->absis = 0;
    T->ordinat = 0;
}

/* getAbsis */
int getAbsis(Titik T){
    return T.absis;
}

/* getOrdinat */
int getOrdinat(Titik T){
    return T.ordinat;
}

/* setAbsis */
void setAbsis(Titik *T, int x){
    T ->absis = x;
}

/* setOrdinat */
void setOrdinat(Titik *T, int y){
    T ->ordinat = y;
}

/* isOrigin */
boolean isOrigin(Titik T){
    if (T.absis == 0 && T.ordinat == 0){
        return true;
    } else {
        return false;
    }
}

/* isOnSumbuX */
boolean isOnSumbuX(Titik T){
    if (T.ordinat == 0) {
        return true;
    }
    else {
        return false;
    }
}

/* isOnSumbuY */
boolean isOnSumbuY(Titik T){
    if (T.absis == 0){
        return true;
    }
    else {
        return false;
    }
}

/* isEqual */
boolean isEqual(Titik T1, Titik T2){
    if ((T1.absis == T2.absis) && (T1.ordinat == T2.ordinat)){
        return true;
    }
    else {
        return false;
    }   
}

/* geser */
void geser(Titik *T, int x, int y){
    T->absis = getAbsis(*T) + x;
    T->ordinat = getOrdinat(*T) + y;
}

/* refleksiX */
void refleksiX(Titik *T){
    T->ordinat = -getOrdinat(*T);
}

/* refleksiY */
void refleksiY(Titik *T){
    T->absis = -getAbsis(*T);
}

/* dilatasi */
void dilatasi(Titik *T, float k){
    T->absis = getAbsis(*T) * k;
    T->ordinat = getOrdinat(*T) * k;
}

/* dilatasiX */
void dilatasiX(Titik *T, Titik X, float k){
    T->absis = k * (getAbsis(*T) - getAbsis(X)) + getAbsis(X);
    T->ordinat = k * (getOrdinat(*T) - getOrdinat(X)) + getOrdinat(X); 
}

/* kuadran */
int kuadran(Titik T){
    if (T.absis > 0 && T.ordinat > 0){
        return 1;
    }
    else if (T.absis < 0 && T.ordinat > 0){
        return 2;
    }
    else if (T.absis > 0 && T.ordinat < 0){
        return 3;
    }
    else if (T.absis < 0 && T.ordinat < 0){
        return 4;
    }
    else {
        return 0;
    }
}