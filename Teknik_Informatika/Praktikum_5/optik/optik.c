#include "optik.h"
#include <string.h>
#include <stdio.h>

/* ===================== KONSTRUKTOR ===================== */

void CreateLensa(Lensa *L, double fokus, char tipe[])
/* Membuat ADT Lensa dengan titik fokus dan jenis yang diberikan.
 * Pre  : fokus != 0; tipe adalah "Cembung" atau "Cekung".
 * Post : L->f = fokus, L->jenis berisi salinan tipe.
 */
{
    L->f = fokus;
    strncpy(L->jenis, tipe, 10);
}

void CreateBenda(Benda *B, double jarak, double tinggi)
/* Membuat ADT Benda dengan jarak dan tinggi yang diberikan.
 * Pre  : jarak > 0; tinggi > 0.
 * Post : B->s = jarak, B->h = tinggi.
 */
{
    B->h = tinggi;
    B->s = jarak;
}

Bayangan HitungBayangan(Lensa L, Benda B)
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
{
    Bayangan result;
    result.s_aks = 1.0 / (1.0 / L.f - 1.0 / B.s);
    result.M = - result.s_aks / B.s;
    result.h_aks = result.M * B.h;

    result.isNyata = result.s_aks > 0;
    result.isTegak = result.M > 0;

    return result;
}

void VisualisasiBayangan(Bayangan Bay)
/* Mencetak seluruh properti Bayangan ke layar dalam format yang mudah dibaca.
 * Pre  : Bay sudah terdefinisi (hasil dari HitungBayangan).
 * Post : Mencetak s_aks, h_aks, M, sifat nyata/maya, dan sifat tegak/terbalik.
Tidak mengubah nilai apapun di dalam Bay.
 * Contoh Keluaran:
Jarak Bayangan (s'): 11.11 cm
Tinggi Bayangan (h'): -0.89 cm
Perbesaran (M): -0.11 x
Sifat: Nyata, Terbalik
 */
{
    printf("Jarak Bayangan (s'): %.2f cm\nTinggi Bayangan (h'): %.2f "
           "cm\nPerbesaran (M): %.2f x\nSifat: ",
           Bay.s_aks, Bay.h_aks, Bay.M);

	if (Bay.isNyata) {
		printf("Nyata, ");
	} else {
		printf("Maya, ");
	}

	if (Bay.isTegak) {
		printf("Tegak\n");
	} else {
		printf("Terbalik\n");
	}
}
