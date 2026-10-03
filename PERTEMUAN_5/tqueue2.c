/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul queue model II */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 23 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

void createQueue2(tqueue2 *Q) {
	/* kamus lokal */
	int i;
	/* algoritma */
	for (i = 1; i <= 5; i++) {
		(*Q).wadah[i] = '#';
	}
	(*Q).head = 0;
	(*Q).tail = 0;
}

boolean isEmptyQueue2(tqueue2 Q) {
	/* algoritma */
	if (Q.head == 0 && Q.tail == 0) {
		return true;
	} else {
		return false;
	}
}

boolean isFullQueue2(tqueue2 Q){
	if (Q.head == 1 && Q.tail == 5){
		return true;
	} else {
		return false;
	}
}

boolean isOneElement2(tqueue2 Q){
	if (Q.head != 0 && Q.head == Q.tail){
		return true;
	} else {
		return false;
	}
}

int head2(tqueue2 Q){
	return Q.head;
}

int tail2(tqueue2 Q){
	return Q.tail;
}

char infoHead2(tqueue2 Q){
	if (isEmptyQueue2(Q)){
		return '#';
	} else {
		return Q.wadah[Q.head];
	}
}

char infoTail2(tqueue2 Q){
	if (isEmptyQueue2(Q)){
		return '#';
	} else {
		return Q.wadah[Q.tail];
	}
}

int sizeQueue2(tqueue2 Q){
	if (isEmptyQueue2(Q)){
		return 0;
	} else {
		return (Q.tail - Q.head + 1);
	}
}

void printQueue2(tqueue2 Q){
	int i;
	if (Q.head != 0){
		for (i = 1; i <= Q.tail; i++){
			printf("%c\n", Q.wadah[i]);
		}
	}
}

void viewQueue2(tqueue2 Q){
	int i;
	if (Q.head != 0){
		for (i = 1; i <= Q.tail; i++){
			if (Q.wadah[i] != 0){
				printf("%c\n", Q.wadah[i]);
			}
		}
	}
}

boolean isTailStop(tqueue2 Q){
	if (Q.tail == 5){
		return true;
	} else {
		return false;
	}
}

void resetHead(tqueue2 *Q){
	int i, panjang, headlama;
	panjang = (*Q).tail - (*Q).head + 1;
	headlama = (*Q).head;

	if (isEmptyQueue2(*Q)){
		return ;
	}

	for (i = 0; i < panjang; i++){
		(*Q).wadah[i + 1] = (*Q).wadah[headlama];
		headlama++;
	}

	(*Q).head = 1;
	(*Q).tail = panjang;
}

void enqueue2(tqueue2 *Q, char E){
	int i;

	if (!isFullQueue2(*Q)){
		if (isEmptyQueue2(*Q)){
			(*Q).head = 1;
			(*Q).tail = 1;
			(*Q).wadah[1] = E;
		} else if ((*Q).tail < 5){
			(*Q).tail++;
			(*Q).wadah[(*Q).tail] = E;
		} else if ((*Q).tail >= 5){
			resetHead(Q);
			(*Q).tail++;
			(*Q).wadah[(*Q).tail] = E;
		}
	}
}

void dequeue2(tqueue2 *Q, char *E){
	if (isEmptyQueue2(*Q)){
		*E = '@';
	} else {
		*E = infoHead2(*Q);
		(*Q).wadah[(*Q).head] = '#';
		if (isOneElement2(*Q)){
			(*Q).head = 0;
			(*Q).tail = 0;
		} else {
			(*Q).head++;
		}
	}
}

void enqueue2N(tqueue2 *Q, int N){
	int i;
	char e;

	for (i = 1; i <= N; i++){
		if (isFullQueue2(*Q)){
			printf("Queue penuh, elemen ke-%d tidak dapat dimasukkan.\n", i);
			break;
		}
		printf("Masukkan elemen ke-%d: ", i);
		scanf(" %c", &e);
		enqueue2(Q, e);
	}
	printf("\nQueue baru: \n", *Q);
	printQueue2(*Q);

}

boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
	int i;
	
	if (sizeQueue2(Q1) != sizeQueue2(Q2)){
		return false;
	}
	
	for (i = 0; i < sizeQueue2(Q1); i++){
		if (Q1.wadah[Q1.head + i] != Q2.wadah[Q2.head + i]){
			return false;
			break;
		}
	}
	return true;

}