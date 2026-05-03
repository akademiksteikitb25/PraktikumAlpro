#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "boolean.h"

/* Kamus Umum */
#define MAX_OPERAND 100
#define MAX_OPERATOR 99

typedef struct {
    int Operan[MAX_OPERAND];
    char Operator[MAX_OPERATOR]; // Jenis Operator: +, -, *, /. Prekondisi: Operator dijamin valid
    int Ans;
    int NEffOperan;
    int NEffOperator;
} Kalkulator;


void BuatKalkulator (Kalkulator *K);
/* Membuat kalkulator kosong
 I.S. K sembarang
 F.S. Terbentuk kalkulator K kosong */

boolean CekError (Kalkulator K);
/* Mengembalikan nilai true jika kalkulator akan mengeluarkan error dan false jika tidak ada error */

void ResetKalkulator (Kalkulator *K);
/* Menghapus keseluruhan data pada kalkulator K */

void InputOperasi (Kalkulator *K, int oprn[], int n_oprn, char oprtor[], int n_oprtor);
/* Menerima sekumpulan array operan dan operator sekaligus beserta panjangnya,
   lalu menyimpannya ke dalam kalkulator K
   Pastikan untuk mengosongkan kalkulator K dulu sebelum memasukkan input baru */

void TambahOperator (Kalkulator *K, char oprtor);
/* Menambahkan operator di akhir list */

void HapusOperator (Kalkulator *K);
/* Menghapus operator di akhir list */

void UbahOperator (Kalkulator *K, int idx, char oprtor);
/* Mengubah operator pada posisi idx */

void TambahOperan (Kalkulator *K, int oprn);
/* Menambahkan operan di akhir list */

void HapusOperan (Kalkulator *K);
/* Menghapus operan di akhir list */

void UbahOperan (Kalkulator *K, int idx, int oprn);
/* Mengubah operan pada posisi idx */

boolean JalankanKalkulasi (Kalkulator *K);
/* Jika kalkulasi valid dan berhasil:
   - Hasil kalkulasi disimpan ke Ans dan fungsi akan mengembalikan true.
   Jika kalkulasi tidak valid dan gagal:
   - Hasil kalkulasi tidak disimpan ke Ans dan fungsi akan mengembalikan false
   Note: Abaikan presedensi operator, cukup ikuti urutan pada list */

void CetakHasil (Kalkulator K);
/* Mencetak operan dan operasi yang terlibat serta menampilkan hasil kalkulasi
Contoh 1:
4+2*5-7
Hasil Kalkulasi: 7

Contoh 2:
4+2*5-
Hasil Kalkulasi: ERROR

Contoh 3 (Kalkulator Kosong):
KALKULATOR MASIH KOSONG
Jangan lupa akhiri dengan newline ('\n') */

#endif
