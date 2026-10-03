/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul queue model II */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 23 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main() {
	/* kamus */
	tqueue2 A, B;
	char e = 'J';

	/*Algoritma*/
	createQueue2(&A);
	printf("\nQueue2 A: \n");
	enqueue2(&A, 'J');
	enqueue2(&A, 'O');
	enqueue2(&A, 'S');
	enqueue2(&A, 'E');
	enqueue2(&A, 'P');
	printQueue2(A);
	printf("Head: %c\n", infoHead2(A));
	printf("Tail: %c\n", infoTail2(A));
	printf("Ukuran: %d\n", sizeQueue2(A));
	printf("Apakah full: %s\n", isFullQueue2(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue2(A) ? "true" : "false");
	printf("Apakah Tail Stop: %s\n", isTailStop(A) ? "true" : "false");
	printf("\n");
	printf("Queue A setelah dequeue J: \n");
	dequeue2(&A, &e);
	printQueue2(A);
	printf("Head: %c\n", infoHead2(A));
	printf("Tail: %c\n", infoTail2(A));
	printf("Ukuran: %d\n", sizeQueue2(A));
	printf("Apakah full: %s\n", isFullQueue2(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue2(A) ? "true" : "false");
	printf("Apakah Tail Stop: %s\n", isTailStop(A) ? "true" : "false");
	printf("\n");
	printf("Queue A setelah enqueue H: \n");
	enqueue2(&A, 'H');
	printQueue2(A);
	printf("Head: %c\n", infoHead2(A));
	printf("Tail: %c\n", infoTail2(A));
	printf("Ukuran: %d\n", sizeQueue2(A));
	printf("Apakah full: %s\n", isFullQueue2(A) ? "true" : "false");
	printf("Apakah kosong: %s\n", isEmptyQueue2(A) ? "true" : "false");
	printf("Apakah Tail Stop: %s\n", isTailStop(A) ? "true" : "false");
	printf("\n");
	createQueue2(&B);
	printf("Membuat Queue B sebanyak 4 elemen: \n");
	enqueue2N(&B, 5);
	printf("\n");
	printf("Apakah Queue A dan B sama: %s\n", isEqualQueue2(A, B) ? "true" : "false");
	printf("\n");
	return 0;
}
