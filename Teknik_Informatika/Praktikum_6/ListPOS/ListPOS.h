#ifndef LIST_POS_H
#define LIST_POS_H

#include "boolean.h"

/* Kamus Umum */
#define CAPACITY 20
#define IDX_UNDEF -1

/* Definisi elemen list */
typedef struct {
    int idPesanan;   /* ID Pesanan DIJAMIN UNIK */
    int waktuMasuk;  /* Waktu pesanan masuk DIJAMIN UNIK */
    int totalItem;
    int hargaPerItem;
} Pesanan;

typedef struct {
    Pesanan buffer[CAPACITY];
    int neff;
} ListPOS;

/* Konstruktor : create list POS kosong */
void CreateListPOS(ListPOS *l);

/* Mengecek list kosong
 * Mengirimkan true jika list kosong, mengirimkan false jika tidak */
boolean IsEmpty(ListPOS l);

/* Mengecek list penuh */
/* Mengirimkan true jika list penuh, mengirimkan false jika tidak */
boolean IsFull(ListPOS l);

/* Mencari indeks Pesanan berdasarkan idPesanan */
/* Kembalikan IDX_UNDEF jika tidak ditemukan */
int CariIndeksPesanan(ListPOS l, int idPesanan);

/* Menambahkan pesanan ke akhir list (insert last) */
/* Jika list penuh, print "GAGAL MENAMBAHKAN" diakhiri dengan newline  */
void TambahPesanan(ListPOS *l, Pesanan p);

/* Menghapus pesanan dengan waktuMasuk paling awal, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika berhasil menyelesaikan pesanan, kembalikan nilai true dan simpan pesanan ke variabel pointer *p */
/* Jika tidak ada pesanan yang bisa diselesaikan, print "GAGAL MENYELESAIKAN" diakhiri dengan newline, dan kembalikan nilai false */
boolean SelesaikanPesanan(ListPOS *l, Pesanan *p);

/* Menghapus pesanan sesuai idPesanan, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika tidak ada pesanan yang bisa dibatalkan, print "GAGAL MEMBATALKAN" diakhiri dengan newline */
void BatalkanPesanan(ListPOS *l, int idPesanan);

/* Mengembalikan jumlah harga total pesanan dengan id idPesanan */
/* Kembalikan 0 jika pesanan tidak ada */
int HitungHargaTotalPesanan(ListPOS l, int idPesanan);

/* Mengembalikan jumlah item total seluruh pesanan di list */
int HitungSemuaItem(ListPOS l);

/* Mengembalikan jumlah harga total seluruh pesanan di list */
int HitungSemuaHargaTotal(ListPOS l);

/* Mencetak pesanan ke layar dengan format:

   {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan diakhiri dengan newline */
void CetakPesanan(Pesanan p);


/* Mencetak semua pesanan di list ke layar dengan format:

   [1] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   [2] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   ...
   [N] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan setiap baris diakhiri dengan newline */
void CetakSemuaPesanan(ListPOS l);

#endif
