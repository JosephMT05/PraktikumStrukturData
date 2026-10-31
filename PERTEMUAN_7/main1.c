/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal : 28 Oktober 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main() { 
  //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  List1 L, L1, L2, LConcat, LCopy;
  infotype V;
  
  //algoritma
  //aplikasi tipe address
  
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }
  //PrintList( Senarai );
  PrintList( Senarai );
  printf("\n");

  printf("\n=== CreateList & IsEmptyList ===");
  CreateList(&L);
  printf("\nIsEmptyList? %d", IsEmptyList(L));
  printf("\nNbElm = %d\n", NbElm(L));

  printf("\n=== Uji InsertVFirst & InsertVLast ===");
  InsertVFirst(&L, 'A');
  InsertVFirst(&L, 'I');
  InsertVLast(&L, 'R');
  InsertVLast(&L, 'A');
  InsertVLast(&L, 'M');
  InsertVFirst(&L, 'K');
  PrintList(L); 
  printf("\nIsEmptyList(L)? %d", IsEmptyList(L));
  printf("\nNbElm(L) = %d\n", NbElm(L));

  printf("\n=== Uji InsertVAfter ===");
  printf("\nInsert 'S' setelah 'A' pertama:");
  InsertVAfter(&L, 'A', 'S');
  PrintList(L); 
  printf("\n");

  printf("\n=== Uji SearchX & SearchAllX ===");
  P = Alokasi('#'); 
  SearchX(L, 'A', &P);
  printf("\nSearchX 'A' ditemukan info = %c", info(P));
  SearchAllX(L, 'A');
  SearchAllX(L, 'Z');
  printf("\n");

  printf("\n=== Uji UpdateX & UpdateAllX ===");
  printf("\nUpdateX 'K' menjadi 'T':");
  UpdateX(&L, 'K', 'T');
  PrintList(L); 
  
  InsertVLast(&L, 'A');
  printf("\nSetelah tambah 'A' di akhir:");
  PrintList(L); 
  
  printf("\nUpdateAllX 'A' menjadi 'O':");
  UpdateAllX(&L, 'A', 'O');
  PrintList(L); 
  printf("\n");

  printf("\n=== Uji Statistik Elemen List ===");
  printf("\nCountX('O')        = %d", CountX(L, 'O'));
  printf("\nFrekuensiX('O')    = %.2f", FrekuensiX(L, 'O'));
  printf("\nCountKonsonan      = %d", CountKonsonan(L, 'O'));
  printf("\nModus(L)           = %c", Modus(L));
  printf("\nNbModus(L)         = %d\n", NbModus(L));

  printf("\n=== Uji Invers List ===");
  printf("\nSebelum Invers:");
  PrintList(L);
  Invers(&L);
  printf("\nSesudah Invers:");
  PrintList(L);
  printf("\n");

  printf("\n=== Uji DeleteVFirst & DeleteVLast ===");
  DeleteVFirst(&L, &V);
  printf("\nDeleteVFirst menghapus : %c", V);
  PrintList(L);
  
  DeleteVLast(&L, &V);
  printf("\nDeleteVLast menghapus  : %c", V);
  PrintList(L);
  printf("\n");

  printf("\n=== Uji CopyList, SplitList, & ConcatList ===");
  CopyList(L, &LCopy);
  printf("\nHasil CopyList L ke LCopy:");
  PrintList(LCopy);

  SplitList(L, &L1, &L2);
  printf("\nHasil SplitList L -> L1:");
  PrintList(L1);
  printf("\nHasil SplitList L -> L2:");
  PrintList(L2);

  ConcatList(L1, L2, &LConcat);
  printf("\nHasil ConcatList L1 dan L2 -> LConcat:");
  PrintList(LConcat);
  printf("\n");
  return 0;
}