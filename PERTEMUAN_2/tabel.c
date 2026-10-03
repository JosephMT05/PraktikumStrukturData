#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"

/* Deskripsi : Realisasi tabel.h*/
/* NIM/Nama : Joseph Marco Tanuwidjaja*/
/* Tanggal : 2 September 2026*/

void createTable(Tabel *T){
    T->size = 0;
    for(int i=1; i<=10; i++){
        T->wadah[i] = ' ';
    }
}

int getSize(Tabel T){
    return T.size;
}

boolean isEmptyTable(Tabel T){
    if (getSize(T) == 0){
        return true;
    }
    else {
        return false;
    }
}

boolean isFullTable(Tabel T){
    if (getSize(T) == 10){
        return true;
    }
    else {
        return false;
    }
}

void searchX(Tabel T, char x, int *pos){
    // Kamus
    int i;
    boolean found = false;
    *pos = -999;

    // Algoritma
    if (!isEmptyTable(T)){
        for (i=1; i<=getSize(T) && !found; i++){
            if (T.wadah[i] == x){
                found = true;
                *pos = i;
            }
        }
    }



}
        

int CountX(Tabel T, char x){
    int count = 0;
    for(int i=1; i<=T.size; i++){
        if(T.wadah[i] == x){
            count++;
        }
    }
    return count;
}

int CountVocal(Tabel T){
    int count = 0;
    for(int i=1; i<=T.size; i++){
        char c = T.wadah[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            count++;
        }
    }
    return count;
}

void addXTable(Tabel *T, char x){
    if(!isFullTable(*T)){
        T->size++;
        T->wadah[getSize(*T)] = x;
    }
}

void addUniqueXTable(Tabel *T, char x){
    if(!isFullTable(*T)){
        int pos;
        searchX(*T, x, &pos);
        if(pos == -999){
            addXTable(T, x);
        }
    }
}

void delXTable(Tabel *T, char x){
    if(!isEmptyTable(*T)){
        int pos;
        searchX(*T, x, &pos);

        if(pos != -999){
            for(int i = pos; i < getSize(*T); i++){
                T->wadah[i] = T->wadah[i+1];
            }
            T->wadah[getSize(*T)] = ' ';
            T->size--;
        }
    }
}

void delTable(Tabel *T, int idx){
    if(!isEmptyTable(*T) && idx >= 1 && idx <= T->size){
        for(int i=idx; i<T->size; i++){
            T->wadah[i] = T->wadah[i+1];
        }
        T->size--;
    }
}

void delAllXTable(Tabel *T, char x){
    if(!isEmptyTable(*T)){
        int pos;

        searchX(*T, x, &pos);
        
        while(pos != -999){
            delXTable(T, x);
            searchX(*T, x, &pos);
        }
    }
}

void printTable(Tabel T){
    printf("Tabel contents: ");
    for(int i=1; i<=T.size; i++){
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

void viewTable(Tabel T){
    printf("Tabel contents: ");
    for(int i=1; i<=T.size; i++){
        if (T.wadah[i] != ' ') {
            printf("%c ", T.wadah[i]);
        }
    }
    printf("\n");
}

void populateTable(Tabel *T, int N){
    // Kamus
    // Algoritma
    for (int i = 1; i <= N; i++){
            char x, input;
            printf("Masukkan elemen ke-%d: ", i);
            input = scanf(" %c", &x);
            T->wadah[i] = x;
        }
    }

int Modus(Tabel T){
    int maxCount = 0;
    char modus = ' ';
    for(int i=1; i<=T.size; i++){
        int count = CountX(T, T.wadah[i]);
        if(count > maxCount){
            maxCount = count;
            modus = T.wadah[i];
        }
    }
    return modus;
}
#endif