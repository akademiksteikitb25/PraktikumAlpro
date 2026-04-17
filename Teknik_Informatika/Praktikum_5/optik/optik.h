#ifndef OPTIK_H
#define OPTIK_H

#include "boolean.h"

/* ADT LENSA */
typedef struct {
    double f;       /* Titik fokus lensa (cm).
                    *  Bernilai positif untuk lensa cembung (konvergen),
                    *  bernilai negatif untuk lensa cekung (divergen). */
    char jenis[10]; /* Jenis lensa: "Cembung" atau "Cekung". */
} Lensa;


/* ADT BENDA */
typedef struct {
    double s;  /* Jarak benda ke lensa (cm). Selalu bernilai positif. */
    double h;  /* Tinggi benda (cm). Bernilai positif jika tegak. */
} Benda;


/* ADT BAYANGAN */
typedef struct {
    double s_aks;    /* Jarak bayangan ke lensa (cm).
                      * Positif  → bayangan di sisi berlawanan dari benda (nyata).
                      * Negatif  → bayangan di sisi yang sama dengan benda (maya). */
    double h_aks;    /* Tinggi bayangan (cm).
                      * Positif  → bayangan tegak.
                      * Negatif  → bayangan terbalik. */
    double M;        /* Perbesaran linear bayangan (tak bersatuan).
                      * |M| > 1  → bayangan lebih besar dari benda.
                      * |M| < 1  → bayangan lebih kecil dari benda.
                      * |M| = 1  → bayangan sama besar dengan benda. */
    boolean isNyata; /* TRUE jika bayangan nyata (s' > 0), FALSE jika maya. */
    boolean isTegak; /* TRUE jika bayangan tegak (M > 0), FALSE jika terbalik. */
} Bayangan;


/* ===================== KONSTRUKTOR ===================== */

void CreateLensa(Lensa *L, double fokus, char tipe[]);
/* Membuat ADT Lensa dengan titik fokus dan jenis yang diberikan.
 * Pre  : fokus != 0; tipe adalah "Cembung" atau "Cekung".
 * Post : L->f = fokus, L->jenis berisi salinan tipe.
 */

void CreateBenda(Benda *B, double jarak, double tinggi);
/* Membuat ADT Benda dengan jarak dan tinggi yang diberikan.
 * Pre  : jarak > 0; tinggi > 0.
 * Post : B->s = jarak, B->h = tinggi.
 */

Bayangan HitungBayangan(Lensa L, Benda B);
/* Menghitung bayangan yang terbentuk dari Benda B melalui Lensa L.
 * Menggunakan rumus lensa tipis:
 *     1/s' = 1/f - 1/s
 * dan perbesaran:
 *     M = -s'/s,  h' = M * h
 *
 * Pre  : L dan B sudah terdefinisi; B.s != L.f (benda tidak tepat di fokus).
 * Post : Mengembalikan Bayangan dengan s_aks, h_aks, M, isNyata, dan isTegak
 *        yang dihitung berdasarkan rumus di atas.
 *        isNyata = TRUE  jika s_aks > 0.
 *        isTegak = TRUE  jika M > 0.
 */

void VisualisasiBayangan(Bayangan Bay);
/* Mencetak seluruh properti Bayangan ke layar dalam format yang mudah dibaca.
 * Pre  : Bay sudah terdefinisi (hasil dari HitungBayangan).
 * Post : Mencetak s_aks, h_aks, M, sifat nyata/maya, dan sifat tegak/terbalik. Tidak mengubah nilai apapun di dalam Bay.
 * Contoh Keluaran:
Jarak Bayangan (s'): 11.11 cm
Tinggi Bayangan (h'): -0.89 cm
Perbesaran (M): -0.11 x
Sifat: Nyata, Terbalik
 */


#endif
