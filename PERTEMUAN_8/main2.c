/* File : main2.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 6 November 2026*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main()
{ // kamus
  address A; 
  address B;
  address P;
  List2 Senarai;
  List2 L, L1, L2, LConcat, LCopy;
  infotype V;

  // Algoritma
  // Aplikasi tipe address & List2 Sirkular manual
  printf("=== Uji Tipe Address Sirkular Manual ===\n");
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  A->info = 'G';   A->next = B; // Sirkular: elemen terakhir menunjuk ke First (B)
  B->info = 'N';   B->next = A;
  printf("info(A)=%c\tinfo(B)=%c\n", A->info, B->info);
  
  Senarai.First = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  if (P != NIL) {
      do {
          printf("\t%c", info(P));
          P = next(P);
      } while (P != First(Senarai));
  }
  PrintList(Senarai);
  printf("\n");

  // Uji CreateList, IsEmptyList, & IsOneElm
  printf("\n=== Uji CreateList, IsEmptyList, & IsOneElm ===");
  CreateList(&L);
  printf("\nIsEmptyList(L)? %d", IsEmptyList(L));
  printf("\nIsOneElm(L)?    %d", IsOneElm(L));
  printf("\nNbElm(L)      = %d\n", NbElm(L));

  // Uji InsertVFirst & InsertVLast
  printf("\n=== Uji InsertVFirst & InsertVLast ===");
  InsertVFirst(&L, 'A');
  printf("\nSetelah InsertVFirst 'A':");
  PrintList(L);
  printf("\nIsOneElm(L)? %d", IsOneElm(L));  
  printf("\nInsert elemen M sebelum elemen A dan elemen U, N, D, A, U setelah elemen A");
  InsertVFirst(&L, 'M');
  InsertVLast(&L, 'U');
  InsertVLast(&L, 'N');
  InsertVLast(&L, 'D');
  InsertVLast(&L, 'A');
  InsertVLast(&L, 'U');
  PrintList(L); 
  printf("\nNbElm(L) = %d\n", NbElm(L));

  // Uji InsertVAfterX & InsertVBeforeX
  printf("\n=== Uji InsertVAfterX & InsertVBeforeX ===");
  printf("\nInsertVAfterX 'N' dengan 'A':");
  InsertVAfterX(&L, 'N', 'A');
  PrintList(L);   
  
  printf("\nInsertVBeforeX 'M' (First) dengan 'K':");
  InsertVBeforeX(&L, 'M', 'K');
  PrintList(L); 
  printf("\n");

  // Uji SearchX & SearchAllX
  printf("\n=== Uji SearchX & SearchAllX ===");
  SearchX(L, 'A', &P);
  if (P != NIL) {
      printf("\nSearchX 'A' ditemukan info = %c", info(P));
  }
  SearchAllX(L, 'A'); 
  SearchAllX(L, 'J'); 
  printf("\n");

  // Uji UpdateX & Statistik (CountX, FrekuensiX, CountVocal, CountAU, Modus, MaxMember)
  printf("\n=== Uji UpdateX & Statistik List ===");
  printf("\nUpdateX 'K' menjadi 'S':");
  UpdateX(&L, 'K', 'S');
  PrintList(L);   
  
  printf("\nCountX('A')     = %d", CountX(L, 'A'));
  printf("\nFrekuensiX('A') = %.2f", FrekuensiX(L, 'A'));
  printf("\nCountVocal(L)   = %d", CountVocal(L));
  printf("\nCountAU(L)      = %d", CountAU(L));
  printf("\nModus(L)        = %c", Modus(L));
  printf("\nMaxMember(L)    = %d\n", MaxMember(L));

  // Uji Invers
  printf("\n=== Uji Invers List ===");
  printf("\nSebelum Invers:");
  PrintList(L);
  Invers(&L);
  printf("\nSesudah Invers:");
  PrintList(L);
  Invers(&L); 
  printf("\nInvers kembali:");
  PrintList(L);
  printf("\n");

  // Uji DeleteVFirst, DeleteVLast, DeleteX, DeleteVAfterX, DeleteVBeforeX, DeleteAllX
  printf("\n=== Uji Operasi Penghapusan ===");
  DeleteVFirst(&L, &V);
  printf("\nDeleteVFirst menghapus : %c", V);
  PrintList(L);   
  
  DeleteVLast(&L, &V);
  printf("\nDeleteVLast menghapus  : %c", V);
  PrintList(L);   
  
  DeleteVAfterX(&L, 'U', &V);
  printf("\nDeleteVAfterX setelah 'U' menghapus : %c", V);
  PrintList(L);   
  
  DeleteVBeforeX(&L, 'D', &V);
  printf("\nDeleteVBeforeX sebelum 'D' menghapus : %c", V);
  PrintList(L);   
  
  printf("\nDeleteX 'U':");
  DeleteX(&L, 'U');
  PrintList(L);   
  
  printf("\nDeleteAllX 'A':");
  DeleteAllX(&L, 'A');
  PrintList(L); 
  printf("\n");

  // Uji CopyList, SplitList, & ConcatList
  printf("\n=== Uji CopyList, SplitList, & ConcatList ===");
  printf("\nInsert elemen I, K, A di akhir list L");
  InsertVLast(&L, 'I');
  InsertVLast(&L, 'K');
  InsertVLast(&L, 'A');
  printf("\nList L saat ini:");
  PrintList(L);   
  
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