/* Program   : mtqueue3.c */
/* Deskripsi : file DRIVER modul queue model III */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 30 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

int main(){
    /*Kamus*/
    tqueue3 A,B;
    char e = 'J';

    /*Algoritma*/
    createQueue3(&A);
    printf("\nQueue 3 (A): \n");
    enqueue3(&A, 'J');
	enqueue3(&A, 'O');
	enqueue3(&A, 'S');
	enqueue3(&A, 'E');
	enqueue3(&A, 'P');
	printQueue3(A);
    printf("Head: %c\n", infoHead3(A));
	printf("Tail: %c\n", infoTail3(A));
	printf("Ukuran: %d\n", sizeQueue3(A));
	printf("Apakah full: %s\n", isFullQueue3(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue3(A) ? "true" : "false");
    printf("Apakah Tail Overhead: %s\n", isTailOverHead(A) ? "true" : "false");
    printf("\n");
    printf("Queue A setelah dequeue J: \n");
    dequeue3(&A, &e);
    printQueue3(A);
    printf("Head: %c\n", infoHead3(A));
	printf("Tail: %c\n", infoTail3(A));
	printf("Ukuran: %d\n", sizeQueue3(A));
	printf("Apakah full: %s\n", isFullQueue3(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue3(A) ? "true" : "false");
    printf("Apakah Tail Overhead: %s\n", isTailOverHead(A) ? "true" : "false");
    printf("\n");
    printf("Queue A setelah enqueue H: \n");
    enqueue3(&A, 'H');
    printQueue3(A);
    printf("Head: %c\n", infoHead3(A));
	printf("Tail: %c\n", infoTail3(A));
	printf("Ukuran: %d\n", sizeQueue3(A));
	printf("Apakah full: %s\n", isFullQueue3(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue3(A) ? "true" : "false");
    printf("Apakah Tail Overhead: %s\n", isTailOverHead(A) ? "true" : "false");
    printf("\n");
}