/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait SIRKULAR representasi fisik pointer */
/* NIM/Nama  : 24060125140145 / Joseph Marco Tanuwidjaja*/
/* Tanggal   : 6 November 2026*/
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/****************** Manajemen Memori ******************/
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma
    P = (address) malloc(sizeof(Elm)); 
    if (P != NIL) { // jika alokasi memori berhasil
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
 
void Dealokasi (address *P) {
    //kamus lokal

    //algoritma
    if (*P != NIL) { // jika pointer P menunjuk ke alamat yang valid
        next(*P) = NIL;
        free(*P);
        *P = NIL;
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
void CreateList (List2 *L) {
    //kamus lokal

    //algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
boolean IsEmptyList (List2 L) {
    //kamus lokal

    //algoritma
    if (First(L) == NIL) { // jika First tidak menunjuk ke elemen manapun (kosong)
        return true;
    } else { // jika list memiliki minimal satu elemen
        return false;
    }
}

boolean IsOneElm (List2 L) {
    //kamus lokal

    //algoritma
    if (!IsEmptyList(L) && next(First(L)) == First(L)) { // jika list tidak kosong dan next dari First menunjuk ke dirinya sendiri
        return true;
    } else { // jika list kosong atau memiliki lebih dari satu elemen
        return false;
    }
}

/*********** PENELUSURAN ***********/
void PrintList(List2 L) {
    //kamus lokal
    address P;
    //algoritma
    P = First(L);
    if (P != NIL) { // jika list tidak kosong
        printf("\nElemen = ");
        do { // telusuri dan cetak setiap elemen sampai kembali ke First(L)
            printf("\t%c", info(P));
            P = next(P);
        } while (P != First(L) && P != NIL);
    } else { // jika list kosong
        printf("\nList Kosong");
    }
}

int NbElm(List2 L) {
    //kamus lokal
    address P;
    int n;
    //algoritma
    n = 0;
    if (!IsEmptyList(L)) { // jika list tidak kosong, lakukan perhitungan
        P = First(L);
        do { // hitung elemen satu per satu hingga kembali ke First(L)
            n = n + 1;
            P = next(P);
        } while (P != First(L));
    }
    return n;
}

/******* PENAMBAHAN ELEMEN LIST ********/
void InsertVFirst(List2 *L, infotype V ) {
    //kamus lokal
    address P, Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) { // jika alokasi elemen baru berhasil
        if (IsEmptyList(*L)) { // jika list masih kosong, P menunjuk ke dirinya sendiri
            First(*L) = P;
            next(P) = P;
        } else { // jika list sudah berisi elemen
            Last = First(*L);
            while (next(Last) != First(*L)) { // cari elemen terakhir (Last) yang menunjuk ke First
                Last = next(Last);
            }
            next(P) = First(*L);
            next(Last) = P;
            First(*L) = P;
        }
    }
}

void InsertVLast(List2 *L, infotype V ) {
    //kamus lokal
    address P, Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) { // jika alokasi elemen baru berhasil
        if (IsEmptyList(*L)) { // jika list kosong, P menjadi elemen pertama sekaligus terakhir
            First(*L) = P;
            next(P) = P;
        } else { // jika list tidak kosong, sambungkan P setelah Last
            Last = First(*L);
            while (next(Last) != First(*L)) { // telusuri list sampai menemukan elemen terakhir (Last)
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    }
}

/*** PENCARIAN ***/
void SearchX(List2 L, infotype X, address *A) {
    //kamus lokal
    address P;
    boolean Found;
    //algoritma
    *A = NIL;
    if (!IsEmptyList(L)) { // pencarian hanya dilakukan jika list tidak kosong
        P = First(L);
        Found = false;
        do { // telusuri elemen sampai X ditemukan atau kembali ke First(L)
            if (info(P) == X) { // jika info elemen saat ini sama dengan X
                Found = true;
            } else { // jika belum cocok, maju ke elemen berikutnya
                P = next(P);
            }
        } while (P != First(L) && !Found);

        if (Found) { // jika elemen X ditemukan, simpan alamatnya ke *A
            *A = P;
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
void UpdateX(List2 *L, infotype X, infotype Y) {
    //kamus lokal
    address P;
    //algoritma
    SearchX(*L, X, &P);
    if (P != NIL) { // jika elemen bernilai X ditemukan di dalam list
        info(P) = Y;
    }
}

void Invers(List2 *L) {
    //kamus lokal
    address Prev, Curr, NextNode, FirstOld;
    //algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L)) { // pembalikan hanya perlu jika elemen lebih dari satu
        FirstOld = First(*L);
        Prev = First(*L);
        while (next(Prev) != First(*L)) { // cari elemen terakhir untuk dijadikan Prev awal
            Prev = next(Prev);
        }
        Curr = First(*L);
        do { // balik arah pointer next dari setiap elemen satu per satu
            NextNode = next(Curr);
            next(Curr) = Prev;
            Prev = Curr;
            Curr = NextNode;
        } while (Curr != FirstOld);
        First(*L) = Prev;
    }
}

/******* PENGHAPUSAN ELEMEN ********/
void DeleteVFirst(List2 *L, infotype *V) {
    //kamus lokal
    address P, Last;
    //algoritma
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) { // jika hanya 1 elemen, list menjadi kosong
            First(*L) = NIL;
        } else { // jika lebih dari 1 elemen, geser First dan sambungkan Last ke First baru
            Last = First(*L);
            while (next(Last) != First(*L)) { // cari elemen terakhir (Last)
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    } else { // jika list kosong, beri nilai default '#'
        *V = '#';
    }
}

void DeleteVLast(List2 *L, infotype *V) {
    //kamus lokal
    address Last, PrecLast;
    //algoritma
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        if (IsOneElm(*L)) { // jika hanya 1 elemen, hapus elemen tunggal tersebut
            Last = First(*L);
            *V = info(Last);
            First(*L) = NIL;
            Dealokasi(&Last);
        } else { // jika lebih dari 1 elemen, cari elemen terakhir dan elemen sebelumnya
            Last = First(*L);
            PrecLast = NIL;
            while (next(Last) != First(*L)) { // telusuri sampai Last berada di elemen terakhir
                PrecLast = Last;
                Last = next(Last);
            }
            *V = info(Last);
            next(PrecLast) = First(*L);
            Dealokasi(&Last);
        }
    } else { // jika list kosong, beri nilai default '#'
        *V = '#';
    }
}

void DeleteX(List2 *L, infotype X) {
    //kamus lokal
    address P, Prec;
    infotype temp;
    //algoritma
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        SearchX(*L, X, &P);
        if (P != NIL) { // jika elemen X ditemukan
            if (P == First(*L)) { // jika elemen yang dihapus berada di posisi pertama (First)
                DeleteVFirst(L, &temp);
            } else { // jika elemen berada di tengah atau akhir list
                Prec = First(*L);
                while (next(Prec) != P) { // cari elemen pendahulu (Prec) sebelum P
                    Prec = next(Prec);
                }
                next(Prec) = next(P);
                Dealokasi(&P);
            }
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
int CountX(List2 L, infotype X) {
    //kamus lokal
    address P;
    int n;
    //algoritma
    n = 0;
    if (!IsEmptyList(L)) { // jika list tidak kosong
        P = First(L);
        do { // telusuri seluruh elemen list sirkular
            if (info(P) == X) { // jika info elemen sama dengan X, tambah hitungan
                n = n + 1;
            }
            P = next(P);
        } while (P != First(L));
    }
    return n;
}

float FrekuensiX(List2 L, infotype X) {
    //kamus lokal
    int total;
    //algoritma
    total = NbElm(L);
    if (total == 0) { // jika list kosong, hindari pembagian dengan nol
        return 0.0f;
    } else { // jika tidak kosong, hitung rasio kemunculan X terhadap jumlah elemen
        return (float) CountX(L, X) / (float) total;
    }
}

int CountVocal(List2 L) {
    //kamus lokal
    address P;
    int n;
    char c;
    //algoritma
    n = 0;
    if (!IsEmptyList(L)) { // jika list tidak kosong
        P = First(L);
        do { // periksa setiap elemen hingga kembali ke First(L)
            c = info(P);
            if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
                c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') { // jika huruf vokal
                n = n + 1;
            }
            P = next(P);
        } while (P != First(L));
    }
    return n;
}

int CountAU(List2 L) {
    //kamus lokal
    address P;
    int n;
    //algoritma
    n = 0;
    if (!IsEmptyList(L) && !IsOneElm(L)) { // pasangan 'A'-'U' membutuhkan minimal 2 elemen
        P = First(L);
        do { // telusuri pasangan elemen berurutan dalam list sirkular
            if ((info(P) == 'A' || info(P) == 'a') && 
                (info(next(P)) == 'U' || info(next(P)) == 'u')) { // jika elemen saat ini 'A' dan elemen berikutnya 'U'
                n = n + 1;
            }
            P = next(P);
        } while (P != First(L));
    }
    return n;
}

void SearchAllX(List2 L, infotype X) {
    //kamus lokal
    address P;
    int pos;
    boolean ada;
    //algoritma
    pos = 0;
    ada = false;
    printf("\nPosisi '%c' : ", X);
    if (!IsEmptyList(L)) { // jika list tidak kosong
        P = First(L);
        do { // telusuri list sambil mencatat nomor posisi
            pos = pos + 1;
            if (info(P) == X) { // jika elemen bernilai X ditemukan pada posisi ini
                if (ada) { // jika bukan temuan pertama, cetak koma pemisah
                    printf(",%d", pos);
                } else { // jika temuan pertama, cetak langsung angkanya
                    printf("%d", pos);
                }
                ada = true;
            }
            P = next(P);
        } while (P != First(L));
    }
    if (!ada) { // jika X sama sekali tidak ditemukan di dalam list
        printf("0");
    }
}

void InsertVAfterX(List2 *L, infotype X, infotype V) {
    //kamus lokal
    address Prec, P;
    //algoritma
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        SearchX(*L, X, &Prec);
        if (Prec != NIL) { // jika elemen acuan X ditemukan
            P = Alokasi(V);
            if (P != NIL) { // jika alokasi elemen baru berhasil, sisipkan setelah Prec
                next(P) = next(Prec);
                next(Prec) = P;
            }
        }
    }
}

void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    //kamus lokal
    address Target, Prec, P;
    //algoritma
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        SearchX(*L, X, &Target);
        if (Target != NIL) { // jika elemen acuan X ditemukan
            if (Target == First(*L)) { // jika X adalah elemen pertama, sisipkan sebagai elemen pertama baru
                InsertVFirst(L, V);
            } else { // jika X bukan elemen pertama, cari elemen sebelum Target (Prec)
                Prec = First(*L);
                while (next(Prec) != Target) { // telusuri sampai tepat sebelum Target
                    Prec = next(Prec);
                }
                P = Alokasi(V);
                if (P != NIL) { // jika alokasi berhasil, sisipkan P di antara Prec dan Target
                    next(P) = Target;
                    next(Prec) = P;
                }
            }
        }
    }
}

void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    //kamus lokal
    address Prec, PDel;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        SearchX(*L, X, &Prec);
        if (Prec != NIL) { // jika elemen X ditemukan
            PDel = next(Prec);
            if (PDel == First(*L)) { // jika elemen setelah X adalah First (karena sirkular), hapus First
                DeleteVFirst(L, V);
            } else { // jika elemen setelah X bukan First, lepas PDel dari rantai list
                *V = info(PDel);
                next(Prec) = next(PDel);
                Dealokasi(&PDel);
            }
        }
    }
}

void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    //kamus lokal
    address Target, PDel, PrecDel;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) { // jika list tidak kosong
        SearchX(*L, X, &Target);
        if (Target != NIL) { // jika elemen X ditemukan
            if (IsOneElm(*L)) { // jika hanya 1 elemen, elemen sebelum dirinya adalah dirinya sendiri
                DeleteVFirst(L, V);
            } else if (Target == First(*L)) { // jika X di First, elemen sebelumnya adalah Last
                DeleteVLast(L, V);
            } else if (next(First(*L)) == Target) { // jika X di elemen ke-2, elemen sebelumnya adalah First
                DeleteVFirst(L, V);
            } else { // jika X berada di urutan ke-3 atau setelahnya
                PrecDel = First(*L);
                while (next(next(PrecDel)) != Target) { // cari elemen sebelum elemen yang akan dihapus (PrecDel)
                    PrecDel = next(PrecDel);
                }
                PDel = next(PrecDel);
                *V = info(PDel);
                next(PrecDel) = Target;
                Dealokasi(&PDel);
            }
        }
    }
}

void DeleteAllX(List2 *L, infotype X) {
    //kamus lokal
    address P;
    //algoritma
    SearchX(*L, X, &P);
    while (P != NIL) { // ulangi penghapusan selama elemen bernilai X masih ditemukan
        DeleteX(L, X);
        SearchX(*L, X, &P);
    }
}

char Modus(List2 L) {
    //kamus lokal
    address P;
    int c, max;
    char mod;
    //algoritma
    mod = '#';
    max = 0;
    if (!IsEmptyList(L)) { // jika list tidak kosong
        P = First(L);
        do { // periksa frekuensi setiap elemen sampai kembali ke First(L)
            c = CountX(L, info(P));
            if (c > max) { // jika frekuensi elemen ini lebih besar dari rekor tertinggi (max)
                max = c;
                mod = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }
    return mod;
}

int MaxMember(List2 L) {
    //kamus lokal
    address P;
    int c, max;
    //algoritma
    max = 0;
    if (!IsEmptyList(L)) { // jika list tidak kosong
        P = First(L);
        do { // telusuri semua elemen untuk mencari frekuensi tertinggi
            c = CountX(L, info(P));
            if (c > max) { // jika ditemukan jumlah kemunculan yang lebih tinggi dari max
                max = c;
            }
            P = next(P);
        } while (P != First(L));
    }
    return max;
}

/*OPERASI BANYAK LIST*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    //kamus lokal
    address P;
    //algoritma
    CreateList(L);
    if (!IsEmptyList(L1)) { // jika L1 tidak kosong, salin semua elemen L1 ke L
        P = First(L1);
        do { // telusuri L1 sampai kembali ke First(L1)
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    if (!IsEmptyList(L2)) { // jika L2 tidak kosong, sambungkan semua elemen L2 ke akhir L
        P = First(L2);
        do { // telusuri L2 sampai kembali ke First(L2)
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

void SplitList(List2 L, List2 *L1, List2 *L2) {
    //kamus lokal
    address P;
    int n, mid, i;
    //algoritma
    CreateList(L1);
    CreateList(L2);
    if (!IsEmptyList(L)) { // jika list L tidak kosong
        n = NbElm(L);
        mid = (n + 1) / 2;
        P = First(L);
        i = 1;
        do { // bagi elemen ke L1 dan L2 berdasarkan titik tengah (mid)
            if (i <= mid) { // separuh awal masuk ke L1
                InsertVLast(L1, info(P));
            } else { // separuh sisanya masuk ke L2
                InsertVLast(L2, info(P));
            }
            i = i + 1;
            P = next(P);
        } while (P != First(L));
    }
}

void CopyList(List2 L1, List2 *L2) {
    //kamus lokal
    address P;
    //algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) { // jika L1 tidak kosong, salin setiap elemennya ke L2
        P = First(L1);
        do { // telusuri L1 dari awal sampai kembali ke First(L1)
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}