#include "Cursor.h"
#include <stdbool.h>
#include <stdio.h>

/* Kamus Umum */
#define MAX_LENGTH 100

/*
typedef struct {
    char TextInput[MAX_LENGTH];
    int CursorPos; // Posisi kursor yang valid: 0-TextLen
    int TextLen;
} Cursor;
*/

void InitCursor (Cursor *C){
    C->CursorPos=0;
    C->TextLen=0;
}
/* Membuat struct Cursor baru dengan posisi cursor di awal (0) dan belum ada teks apapun pada input */

void MoveLeft (Cursor *C, int step){
    while(C->CursorPos>0 && step){
        C->CursorPos--;
        step--;
    }
}
/* Menggeser posisi cursor ke kiri sejauh step atau sampai berada sebelum karakter pertama text input */

void MoveRight (Cursor *C, int step){
    while(C->CursorPos<C->TextLen && step){
        C->CursorPos++;
        step--;
    }
}
/* Menggeser posisi cursor ke kanan sejauh step atau sampai melewati karakter terakhir text input */

void Type (Cursor *C, char input){
    if(C->TextLen==0 && C->CursorPos==0){
        C->TextInput[0]=input;
        C->TextLen++;
        MoveRight(C, 1);
        return;
    }
    if(C->TextLen<MAX_LENGTH-1 && C->CursorPos==C->TextLen){
        C->TextInput[C->TextLen]=input;
        C->TextLen++;
        MoveRight(C, 1);
        return;
    }
    for(int i=C->TextLen-1; i>=C->CursorPos; i--){
        C->TextInput[i+1]=C->TextInput[i];
    }
    C->TextInput[C->CursorPos]=input;
    C->TextLen++;
    MoveRight(C, 1);
}
/* Menerima karakter input dan menambahkannya di posisi cursor saat ini
Setelah menambahkan karakter, posisi cursor akan bergeser selangkah ke kanan */

void Backspace (Cursor *C){
    if(C->CursorPos<=0){
        return;
    }
    for(int i=C->CursorPos-1; i<C->TextLen-1; i++){
        C->TextInput[i]=C->TextInput[i+1];
    }
    C->TextLen--;
    MoveLeft(C, 1);
}
/* Menghapus satu karakter di kiri posisi cursor saat ini
dan menggeser posisi cursor selangkah ke kiri */

void Home (Cursor *C){
    C->CursorPos=0;
}
/* Memindahkan posisi kursor ke paling awal (sebelum karakter pertama) */

void End (Cursor *C){
    C->CursorPos=C->TextLen;
}
/* Memindahkan posisi kursor ke paling akhir (setelah karakter terakhir) */

void Print (Cursor C){
    for(int i=0; i<C.TextLen; ++i){
        if(i==C.CursorPos){
            printf("|");
        }
        printf("%c", C.TextInput[i]);
    }
    if(C.CursorPos==C.TextLen){
        printf("|");
    }
    printf("\n");
}
/* Mencetak isi dari text input saat ini yang disertai dengan posisi kursor (dilambangkan |), formatnya:
Misal, text input = "halo", posisi kursor = 1, maka cetak:
h|alo
Jangan lupa akhiri dengan newline ("\n") */
