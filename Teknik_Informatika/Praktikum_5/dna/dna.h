#ifndef DNA_H
#define DNA_H

#include "boolean.h"

#define MAX_LEN 1001

typedef struct {
    char rantai[MAX_LEN];   // Sekuens rantai DNA (karakter A, T, G, C)
    int panjang;            // Panjang efektif string DNA (tidak termasuk '\0')
} DNA;


/* KONSTRUKTOR */

void CreateDNA(DNA *D, char seq[]);
/* Membuat ADT DNA dari string seq.
*  Pre  : seq adalah string valid berisi karakter A, T, G, atau C dengan panjang < MAX_LEN.
*  Post : D->rantai berisi salinan seq, D->panjang berisi panjang dari seq.
*/

/* SELEKTOR / PREDIKAT */

boolean IsStartCodon(DNA D, int idx);
/* Mengecek apakah terdapat start codon "ATG" pada posisi idx..idx+2.
*  Pre  : D sudah terdefinisi; 0 <= idx <= D.panjang - 3.
*  Post : Mengembalikan TRUE jika D.rantai[idx..idx+2] == "ATG", FALSE jika selain itu atau idx out of range.
*/

boolean IsStopCodon(DNA D, int idx);
/* Mengecek apakah terdapat stop codon pada posisi idx..idx+2.
*  Stop codon: "TAA", "TAG", "TGA".
*  Pre  : D sudah terdefinisi; 0 <= idx <= D.panjang - 3.
*  Post : Mengembalikan TRUE jika D.rantai[idx..idx+2] adalah salah satu stop codon di atas, FALSE jika selain itu atau idx out of range.
*/


/* OPERASI UTAMA */

DNA EkstrakProtein(DNA D);
/* Mengekstrak ORF (Open Reading Frame) pertama dari rantai DNA D.
*  ORF didefinisikan sebagai:
*    - Dimulai dari start codon pertama ("ATG") yang ditemukan,
*    - Diakhiri oleh stop codon ("TAA", "TAG", atau "TGA") setelahnya,
*    - Jarak antara start codon dan stop codon (eksklusif) habis dibagi 3, sehingga terbentuk rangkaian kodon yang valid.
*  Pre  : D sudah terdefinisi dengan D.panjang > 0.
*  Post : Mengembalikan DNA baru berisi subsequens dari start codon hingga akhir stop codon (inklusif keduanya).
*         Jika tidak ditemukan ORF yang valid, mengembalikan DNA dengan rantai kosong ("") dan panjang 0.
*/

#endif
