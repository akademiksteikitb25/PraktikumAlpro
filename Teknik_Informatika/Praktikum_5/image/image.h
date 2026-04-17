#ifndef IMAGE_H
#define IMAGE_H

#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

/* ***************************************************************** */
/* DEFINISI TYPE PIXEL                                               */
/* ***************************************************************** */
typedef struct {
  int R; /* Red   [0..255] */
  int G; /* Green [0..255] */
  int B; /* Blue  [0..255] */
} PIXEL;

/* *** Notasi Akses: selektor PIXEL *** */
#define Red(P) (P).R
#define Green(P) (P).G
#define Blue(P) (P).B

/* ***************************************************************** */
/* DEFINISI TYPE IMAGE (KANVAS 2D)                                   */
/* ***************************************************************** */
typedef struct {
  PIXEL data[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
} IMAGE;

/* *** Notasi Akses: selektor IMAGE *** */
#define Rows(I) (I).rows
#define Cols(I) (I).cols
#define Elmt(I, i, j) (I).data[i][j]

/* ***************************************************************** */
/* DEFINISI HELPER MACRO                                             */
/* ***************************************************************** */
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

/* ***************************************************************** */
/* VALIDASI DAN KONSTRUKTOR                                          */
/* ***************************************************************** */
bool IsPixelValid(int r, int g, int b);
/* Mengirim TRUE jika nilai R, G, B berada pada rentang [0..255] (inklusif)*/

void CreatePixel(PIXEL *P, int r, int g, int b);
/* I.S. P sembarang, r, g, b terdefinisi */
/* F.S. Jika r, g, b valid, membentuk PIXEL P.
        Jika tidak valid, P diinisialisasi dengan PIXEL hitam (0,0,0) */

void CreateImage(IMAGE *I, int r, int c);
/* I.S. I sembarang, r dan c terdefinisi (0 < r <= MAX_ROWS, 0 < c <= MAX_COLS)
 */
/* F.S. Membentuk IMAGE I dengan ukuran r baris dan c kolom.
        Semua elemen PIXEL di dalamnya diinisialisasi dengan warna hitam (0,0,0)
 */

void CopyImage(IMAGE I1, IMAGE *I2);
/* I.S. I1 terdefinisi, I2 sembarang */
/* F.S. I2 menjadi salinan persis (deep copy bukan hanya reference) dari I1 */

/* ***************************************************************** */
/* OPERASI DASAR PIXEL (FILTERING)                                   */
/* ***************************************************************** */
bool IsPixelEqual(PIXEL P1, PIXEL P2);
/* Mengirim true jika P1 identik dengan P2 (R, G, B sama) */

PIXEL InvertPixel(PIXEL P);
/* Mengirim hasil inverse dari P. (Rumus: R_baru = 255 - R_lama) */

PIXEL GrayscalePixel(PIXEL P);
/* Mengirim hasil konversi P menjadi warna abu-abu.
   (Rumus: R_baru = G_baru = B_baru = (R + G + B) / 3)
   Pembagian integer mengikuti aturan C (truncation toward zero). */

PIXEL AdjustBrightnessPixel(PIXEL P, int delta);
/* Mengirim PIXEL baru yang nilai R, G, B-nya ditambah dengan delta.
   Delta bisa bernilai positif (menerangkan) atau negatif (menggelapkan).
   NOTE: Nilai R, G, B harus tetap valid! */

/* ***************************************************************** */
/* OPERASI DASAR IMAGE                                               */
/* ***************************************************************** */
bool IsImageEqual(IMAGE I1, IMAGE I2);
/* Mengirim true jika I1 dan I2 memiliki ukuran dan isi pixel yang 100% sama */

IMAGE ApplyFilter(IMAGE I, int filterType);
/* Mengembalikan IMAGE baru hasil penerapan filter ke seluruh pixel I.
   Jika filterType == 1: Terapkan InvertPixel
   Jika filterType == 2: Terapkan GrayscalePixel
   Jika tipe lain: Kembalikan salinan I apa adanya. */

IMAGE CropImage(IMAGE I, int startRow, int startCol, int endRow, int endCol);
/* Mengembalikan IMAGE baru berupa potongan (sub-image) dari I.
   Prekondisi: startRow <= endRow, startCol <= endCol, dan koordinat valid.
   Ukuran IMAGE baru adalah (endRow - startRow + 1) x (endCol - startCol + 1).
*/

IMAGE BlendImage(IMAGE I1, IMAGE I2);
/* Mengembalikan IMAGE baru hasil percampuran (overlay) I1 dan I2.
   Prekondisi: Ukuran I1 dan I2 dijamin sama.
   Rumus pixel baru: R_baru = (R_I1 + R_I2) / 2 (Lakukan pada G dan B juga).
*/

#endif

