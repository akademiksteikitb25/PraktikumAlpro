#ifndef CURSOR_H
#define CURSOR_H

#include <stdbool.h>
#include <string.h>

/* Kamus Umum */
#define MAX_LENGTH 100

typedef struct {
    char TextInput[MAX_LENGTH];
    int CursorPos; // Posisi kursor yang valid: 0-TextLen
    int TextLen;
} Cursor;


void InitCursor (Cursor *C);
/* Membuat struct Cursor baru dengan posisi cursor di awal (0) dan belum ada teks apapun pada input */

void MoveLeft (Cursor *C, int step);
/* Menggeser posisi cursor ke kiri sejauh step atau sampai berada sebelum karakter pertama text input */

void MoveRight (Cursor *C, int step);
/* Menggeser posisi cursor ke kanan sejauh step atau sampai melewati karakter terakhir text input */

void Type (Cursor *C, char input);
/* Menerima karakter input dan menambahkannya di posisi cursor saat ini
Setelah menambahkan karakter, posisi cursor akan bergeser selangkah ke kanan */

void Backspace (Cursor *C);
/* Menghapus satu karakter di kiri posisi cursor saat ini
dan menggeser posisi cursor selangkah ke kiri */

void Home (Cursor *C);
/* Memindahkan posisi kursor ke paling awal (sebelum karakter pertama) */

void End (Cursor *C);
/* Memindahkan posisi kursor ke paling akhir (setelah karakter terakhir) */

void Print (Cursor C);
/* Mencetak isi dari text input saat ini yang disertai dengan posisi kursor (dilambangkan |), formatnya:
Misal, text input = "halo", posisi kursor = 1, maka cetak:
h|alo
Jangan lupa akhiri dengan newline ("\n") */

#endif
