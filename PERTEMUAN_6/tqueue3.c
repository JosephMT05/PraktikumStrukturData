/* Program   : tqueue3.c */
/* Deskripsi : file BODY modul queue model III */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 30 September 2026*/
/***********************************/

#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

void createQueue3(tqueue3 *Q){
    /* kamus lokal */
	int i;
	/* algoritma */
	for (i = 1; i <= 5; i++) {
		(*Q).wadah[i] = '-';
	}
	(*Q).head = 0;
	(*Q).tail = 0;
}

boolean isEmptyQueue3(tqueue3 Q){
    if (Q.head == 0 && Q.tail == 0) {
		return true;
	} else {
		return false;
	}
}

boolean isFullQueue3(tqueue3 Q){
    if (isEmptyQueue3(Q)){
		return false;
	} else if (((Q.tail % 5) + 1) == Q.head) {
		return true;
	} else {
        return false;
    }
}

boolean isOneElement3(tqueue3 Q){
    if (Q.head != 0 && Q.head == Q.tail){
		return true;
	} else {
		return false;
	}
}

int head3(tqueue3 Q){
    return Q.head;
}

int tail3(tqueue3 Q){
    return Q.tail;
}

char infoHead3(tqueue3 Q){
    if (isEmptyQueue3(Q)){
		return '#';
	} else {
		return Q.wadah[Q.head];
	}
}

char infoTail3(tqueue3 Q){
    if (isEmptyQueue3(Q)){
		return '#';
	} else {
		return Q.wadah[Q.tail];
	}
}

int sizeQueue3(tqueue3 Q){
    if (isEmptyQueue3(Q)){
		return 0;
	} else if (Q.tail >= Q.head){
		return (Q.tail - Q.head + 1);
    } else {
        return (5 - Q.head + 1) + Q.tail;
    } 
}

void printQueue3(tqueue3 Q){
    int i;
	if (Q.head != 0){
		for (i = 1; i <= 5; i++){
			printf("%c\n", Q.wadah[i]);
		}
	}
}

void viewQueue3(tqueue3 Q){
    int i;
    int posisi = Q.head;
	if (!isEmptyQueue3(Q)){
		for (i = 0; i <= sizeQueue3(Q); i++){
			if (Q.wadah[posisi] != 0){
				printf("%c\n", Q.wadah[posisi]);
                posisi = (posisi % 5) + 1;
			}
		}
	}
}

void enqueue3(tqueue3 *Q, char E){
    if (!isFullQueue3(*Q)){
		if (isEmptyQueue3(*Q)){
			(*Q).head = 1;
			(*Q).tail = 1;
			(*Q).wadah[1] = E;
		} else {
			(*Q).tail = ((*Q).tail % 5) + 1;
			(*Q).wadah[(*Q).tail] = E;
		}
	}
}

void dequeue3(tqueue3 *Q, char *E){
    if (isEmptyQueue3(*Q)){
		*E = ' ';
	} else {
		*E = infoHead3(*Q);
		(*Q).wadah[(*Q).head] = '#';
		if (isOneElement3(*Q)){
			(*Q).head = 0;
			(*Q).tail = 0;
		} else {
			(*Q).head = ((*Q).head % 5) + 1;
		}
	}
}

boolean isTailOverHead(tqueue3 Q){
	if (!isEmptyQueue3(Q) && Q.tail < Q.head){
		return true;
	} else {
		return false;
	}
}