/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue model I */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 23 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

int main() {
	/* kamus */
	tqueue A, B;
	char e1, e2;
	e1 = 'J';
	e2 = 'O';

	/* algoritma */
	createQueue(&A);
	printf("\n");
	enqueue(&A, 'J');
	enqueue(&A, 'O');
	enqueue(&A, 'S');
	enqueue(&A, 'E');
	enqueue(&A, 'P');
	printf("Queue A: \n");
	printQueue(A);
	printf("isEmptyQueue: %s\n", isEmptyQueue(A) ? "true" : "false");
	printf("isFullQueue : %s\n", isFullQueue(A) ? "true" : "false");
	printf("isOneElement: %s\n", isOneElement(A) ? "true" : "false");
	printf("Ukuran Queue: %d\n", sizeQueue(A));
	printf("Head: %c\n", infoHead(A));
	printf("Tail: %c\n", infoTail(A));
	printf("\n");
	dequeue(&A, &e1);
	printf("Queue A setelah dequeue J: \n");
	printQueue(A);
	printf("isEmptyQueue: %s\n", isEmptyQueue(A) ? "true" : "false");
	printf("isFullQueue : %s\n", isFullQueue(A) ? "true" : "false");
	printf("isOneElement: %s\n", isOneElement(A) ? "true" : "false");
	printf("Ukuran Queue: %d\n", sizeQueue(A));
	printf("Head: %c\n", infoHead(A));
	printf("Tail: %c\n", infoTail(A));
	printf("\n");
	createQueue(&B);
	enqueue(&B, 'M');
	enqueue(&B, 'A');
	enqueue(&B, 'R');
	printf("Queue B: \n");
	printQueue(B);
	printf("\n");
	enqueue2(&A, &B, 'C');
	printf("Queue B setelah enqueue2 C: \n");
	printQueue(B);
	printf("\n");
	printf("Queue A: \n");	
	printQueue(A);
	printf("\n");
	dequeue2(&A, &B, &e2);
	printf("Queue A setelah dequeue2 O: \n");
	printQueue(A);
	printf("\n");
	printf("Queue B: \n");	
	printQueue(B);
	return 0;
}
