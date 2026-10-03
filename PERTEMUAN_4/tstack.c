/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 16 September 2026*/
/***********************************/

#include <stdio.h>
#include <stdbool.h>
#include "tstack.h"

void createStack (Tstack *T)
{
    int i;
    for (i = 0; i <= 10; i++) {
        T->wadah[i] = '#';
    }
    T->top = 0;
}

boolean isEmptyStack (Tstack T)
{
    if (T.top == 0) {
        return true;
    } else {
        return false;
    }
}

boolean isFullStack (Tstack T)
{
    if (T.top == 10) {
        return true;
    } else {
        return false;
    }
}

void push (Tstack *T, char E)
{
    if (isFullStack(*T) == false) {
        T->top++;
        T->wadah[T->top] = E;
    }
}

void pop (Tstack *T, char *X)
{
    if (isEmptyStack(*T) == false) {
        *X = T->wadah[T->top];
        T->wadah[T->top] = '#';
        T->top--;
    } else {
        *X = '#';
    }
}

void printStack (Tstack T)
{
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%c", T.wadah[i]);
        if (i < 10) {
            printf(";");
        }
    }
    printf("\n");
}

void viewStack (Tstack T)
{
    int i;
    for (i = 1; i <= T.top; i++) {
        printf("%c", T.wadah[i]);
        if (i < T.top) {
            printf(";");
        }
    }
    printf("\n");
}

bool isPalindrom(char kata[])
{
    Tstack S;
    int i, panjang;
    char X;
    bool hasil = true;

    createStack(&S);

    panjang = 0;
    while (kata[panjang] != '\0') {
        panjang++;
    }

    for (i = 0; i < panjang; i++) {
        push(&S, kata[i]);
    }

    i = 0;
    while (i < panjang && hasil == true) {
        pop(&S, &X);
        if (X != kata[i]) {
            hasil = false;
        }
        i++;
    }

    return hasil;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N)
{
    int i;
    char E;

    for (i = 1; i <= N; i++) {
        if (isFullStack(*T) == false) {
            printf("Masukkan karakter ke-%d: ", i);
            scanf(" %c", &E);
            push(T, E);
        } else {
            printf("Stack penuh.\n");
        }
    }
}