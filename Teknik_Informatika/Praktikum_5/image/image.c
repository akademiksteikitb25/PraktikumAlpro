#include "image.h"

/* ***************************************************************** */
/* VALIDASI DAN KONSTRUKTOR                                          */
/* ***************************************************************** */
bool IsPixelValid(int r, int g, int b)
/* Mengirim TRUE jika nilai R, G, B berada pada rentang [0..255] (inklusif)*/
{
    return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
}

void CreatePixel(PIXEL *P, int r, int g, int b)
/* I.S. P sembarang, r, g, b terdefinisi */
/* F.S. Jika r, g, b valid, membentuk PIXEL P.
        Jika tidak valid, P diinisialisasi dengan PIXEL hitam (0,0,0) */
{
    if (IsPixelValid(r, g, b)) {
        P->R = r;
        P->G = g;
        P->B = b;
    } else {
        P->R = 0;
        P->G = 0;
        P->B = 0;
    }
}

void CreateImage(IMAGE *I, int r, int c)
/* I.S. I sembarang, r dan c terdefinisi (0 < r <= MAX_ROWS, 0 < c <= MAX_COLS)
 */
/* F.S. Membentuk IMAGE I dengan ukuran r baris dan c kolom.
        Semua elemen PIXEL di dalamnya diinisialisasi dengan warna hitam (0,0,0)
 */
{
    if (r < 0 || r >= MAX_ROWS || c < 0 || c >= MAX_COLS)
        return;

    I->cols = c;
    I->rows = r;
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            CreatePixel(&I->data[ri][ci], 0, 0, 0);
        }
    }
}

void CopyImage(IMAGE I1, IMAGE *I2)
/* I.S. I1 terdefinisi, I2 sembarang */
/* F.S. I2 menjadi salinan persis (deep copy bukan hanya reference) dari I1 */
{
    I2->cols = I1.cols;
    I2->rows = I1.rows;

    for (int ri = 0; ri < I1.rows; ri++) {
        for (int ci = 0; ci < I1.cols; ci++) {
            PIXEL p = I1.data[ri][ci];
            I2->data[ri][ci] = p;
        }
    }
}

/* ***************************************************************** */
/* OPERASI DASAR PIXEL (FILTERING)                                   */
/* ***************************************************************** */
bool IsPixelEqual(PIXEL P1, PIXEL P2)
/* Mengirim true jika P1 identik dengan P2 (R, G, B sama) */
{
    return P1.R == P2.R && P1.G == P2.G && P1.B == P2.B;
}

PIXEL InvertPixel(PIXEL P)
/* Mengirim hasil inverse dari P. (Rumus: R_baru = 255 - R_lama) */
{
    P.R = 255 - P.R;
    P.G = 255 - P.G;
    P.B = 255 - P.B;
    return P;
}

PIXEL GrayscalePixel(PIXEL P)
/* Mengirim hasil konversi P menjadi warna abu-abu.
   (Rumus: R_baru = G_baru = B_baru = (R + G + B) / 3)
   Pembagian integer mengikuti aturan C (truncation toward zero). */
{
    int avg = (P.R + P.G + P.B) / 3;
    P.R = avg;
    P.G = avg;
    P.B = avg;
    return P;
}

PIXEL AdjustBrightnessPixel(PIXEL P, int delta)
/* Mengirim PIXEL baru yang nilai R, G, B-nya ditambah dengan delta.
   Delta bisa bernilai positif (menerangkan) atau negatif (menggelapkan).
   NOTE: Nilai R, G, B harus tetap valid! */
{
    P.R = min(255, P.R + delta);
    P.G = min(255, P.G + delta);
    P.B = min(255, P.B + delta);
    return P;
}

/* ***************************************************************** */
/* OPERASI DASAR IMAGE                                               */
/* ***************************************************************** */
bool IsImageEqual(IMAGE I1, IMAGE I2)
/* Mengirim true jika I1 dan I2 memiliki ukuran dan isi pixel yang 100% sama */
{
    if (I1.cols != I2.cols || I1.rows != I2.rows)
        return false;

    for (int ri = 0; ri < I1.rows; ri++) {
        for (int ci = 0; ci < I1.cols; ci++) {
            PIXEL p1 = Elmt(I1, ri, ci);
            PIXEL p2 = Elmt(I2, ri, ci);
            if (p1.R != p2.R || p1.G != p2.G || p1.B != p2.B)
                return false;
        }
    }
    return true;
}

IMAGE ApplyFilter(IMAGE I, int filterType)
/* Mengembalikan IMAGE baru hasil penerapan filter ke seluruh pixel I.
   Jika filterType == 1: Terapkan InvertPixel
   Jika filterType == 2: Terapkan GrayscalePixel
   Jika tipe lain: Kembalikan salinan I apa adanya. */
{
    if (filterType == 1) {
        for (int ri = 0; ri < I.rows; ri++) {
            for (int ci = 0; ci < I.cols; ci++) {
                Elmt(I, ri, ci) = InvertPixel(Elmt(I, ri, ci));
            }
        }
    } else if (filterType == 2) {
        for (int ri = 0; ri < I.rows; ri++) {
            for (int ci = 0; ci < I.cols; ci++) {
                Elmt(I, ri, ci) = GrayscalePixel(Elmt(I, ri, ci));
            }
        }
    }
    return I;
}

IMAGE CropImage(IMAGE I, int startRow, int startCol, int endRow, int endCol)
/* Mengembalikan IMAGE baru berupa potongan (sub-image) dari I.
   Prekondisi: startRow <= endRow, startCol <= endCol, dan koordinat valid.
   Ukuran IMAGE baru adalah (endRow - startRow + 1) x (endCol - startCol + 1).
*/
{
    int rows = endRow - startRow + 1;
    int cols = endCol - startCol + 1;

    IMAGE result;
    CreateImage(&result, rows, cols);
    for (int ri = 0; ri < rows; ri++) {
        for (int ci = 0; ci < cols; ci++) {
            Elmt(result, ri, ci) = Elmt(I, ri + startRow, ci + startCol);
        }
    }
    return result;
}

IMAGE BlendImage(IMAGE I1, IMAGE I2)
/* Mengembalikan IMAGE baru hasil percampuran (overlay) I1 dan I2.
   Prekondisi: Ukuran I1 dan I2 dijamin sama.
   Rumus pixel baru: R_baru = (R_I1 + R_I2) / 2 (Lakukan pada G dan B juga).
*/
{
    IMAGE result;
    CreateImage(&result, I1.rows, I1.cols);

    for (int ri = 0; ri < I1.rows; ri++) {
        for (int ci = 0; ci < I1.cols; ci++) {
            PIXEL p1 = Elmt(I1, ri, ci);
            PIXEL p2 = Elmt(I2, ri, ci);
            PIXEL newp;
            CreatePixel(&newp, (p1.R + p2.R) / 2, (p1.G + p2.G) / 2,
                        (p1.B + p2.B) / 2);
            Elmt(result, ri, ci) = newp;
        }
    }

    return result;
}
