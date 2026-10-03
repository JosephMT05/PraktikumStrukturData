/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 19 September 2026*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"

/* include tstack+boolean */

int main()
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char kata[30];
	char X;

	/* algoritma */
	createStack(&A);

	printf("=== Uji push & tampilan stack ===\n");
	push(&A, 'X');
	push(&A, 'e');
	printf("printStack : ");
	printStack(A);
	printf("viewStack  : ");
	viewStack(A);
	printf("top()      = %d\n", top(A));
	printf("infotop()  = %c\n", infotop(A));

	printf("\n=== Uji isEmptyStack & isFullStack ===\n");
	printf("isEmptyStack(A) = %s\n", isEmptyStack(A) ? "True" : "False");
	printf("isFullStack(A)  = %s\n", isFullStack(A) ? "True" : "False");

	printf("\n=== Uji pop ===\n");
	pop(&A, &X);
	printf("Elemen yang di-pop: %c\n", X);
	printf("viewStack setelah pop: ");
	viewStack(A);

	printf("\n=== Uji pushN ===\n");
	pushN(&A, 3);
	printf("viewStack setelah pushN(3): ");
	viewStack(A);

	printf("\n=== Uji isPalindrom ===\n");
	printf("isPalindrom(ada) --> %s\n", isPalindrom("ada") ? "True" : "False");
	printf("isPalindrom(malam-malam) --> %s\n", isPalindrom("malam-malam") ? "True" : "False");
	printf("isPalindrom(kasur anna rusak) --> %s\n", isPalindrom("kasur anna rusak") ? "True" : "False");
	printf("isPalindrom(malas) --> %s\n", isPalindrom("malas") ? "True" : "False");
	printf("\n");

	return 0;
}
