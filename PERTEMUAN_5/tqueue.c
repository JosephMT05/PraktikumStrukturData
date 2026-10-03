/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue model I */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 23 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

void createQueue(tqueue *Q) {
	/* kamus lokal */
	int i;
	/* algoritma */
	for (i = 1; i <= 5; i++) {
		(*Q).wadah[i] = '-';
	}
	(*Q).head = 0;
	(*Q).tail = 0;
}

int infoHead(tqueue Q){
	if ((Q).head == 0){
		return -999;
	} else {
		return (Q).wadah[(Q).head];
	}
}

int infoTail(tqueue Q){
	if ((Q).tail == 0){
		return -99;
	} else {
		return (Q).wadah[(Q).tail];
	}
}

int sizeQueue(tqueue Q){
	if (isEmptyQueue(Q)){
		return 0;
	} else {
		return Q.tail;
	}
}

void printQueue(tqueue Q){
	int i;
	if (Q.head != 0){
		for (i = 1; i <= Q.tail; i++){
			printf("%c\n", Q.wadah[i]);
		}
	}
}

void viewQueue(tqueue Q){
	int i;
	if (Q.head != 0){
		for (i = 1; i <= Q.tail; i++){
			if (Q.wadah[i] != 0){
				printf("%c\n", Q.wadah[i]);
			}
		}
	}
}

boolean isEmptyQueue(tqueue Q) {
	/* algoritma */
	if (Q.head == 0 && Q.tail == 0) {
		return true;
	} else {
		return false;
	}
}

boolean isFullQueue(tqueue Q){
	/*algoritma*/
	if (Q.head == 1 && Q.tail == 5){
		return true;
	} else {
		return false;
	}
}

boolean isOneElement(tqueue Q){
	if (Q.head != 0 && Q.head == Q.tail){
		return true;
	} else {
		return false;
	}
}

void enqueue(tqueue *Q, char e){
	int i;

	if (!isFullQueue(*Q)){
		if (isEmptyQueue(*Q)){
			(*Q).head = 1;
			(*Q).tail = 1;
			(*Q).wadah[1] = e;
		} else if ((*Q).tail < 5){
			(*Q).tail++;
			(*Q).wadah[(*Q).tail] = e;
		}
	}
}

void dequeue(tqueue *Q, char *e){
	int i;

	if (!isEmptyQueue(*Q)){
		*e = (*Q).head;

		for (i = 1; i < (*Q).tail; i++){
			(*Q).wadah[i] = (*Q).wadah[i + 1]; 
		}
		(*Q).wadah[(*Q).tail] = '-'; 
	}

	if (isOneElement(*Q)){
		(*Q).wadah[(*Q).head] ='-';
		(*Q).head = 0;
		(*Q).tail = 0;
	}

	(*Q).tail--;
}

void enqueue2(tqueue *Q1, tqueue *Q2, char e){
	if (isFullQueue(*Q1) && isFullQueue(*Q2)){
		return ;
	} else if (isFullQueue(*Q1)){
		enqueue(Q2, e);
	} else if (isFullQueue(*Q2)){
		enqueue(Q1, e);
	} else if (sizeQueue(*Q1) <= sizeQueue(*Q2)){
		enqueue(Q1, e);
	} else {
		enqueue(Q2, e);
	}
}

void dequeue2(tqueue *Q1, tqueue *Q2, char *e){
	if (isEmptyQueue(*Q1) && isEmptyQueue(*Q2)){
		*e = '-';
		return ;
	} else if (isEmptyQueue(*Q1)){
		dequeue(Q2, e);
	} else if (isEmptyQueue(*Q2)){
		dequeue(Q1, e);
	} else if (sizeQueue(*Q1) >= sizeQueue(*Q2)){
		dequeue(Q1, e);
	} else {
		dequeue(Q2, e);
	}
}