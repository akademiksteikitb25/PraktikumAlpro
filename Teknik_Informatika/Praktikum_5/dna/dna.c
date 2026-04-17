#include "dna.h"
#include <string.h>

void CreateDNA(DNA *D, char seq[])
/* Membuat ADT DNA dari string seq.
 *  Pre  : seq adalah string valid berisi karakter A, T, G, atau C dengan
 * panjang < MAX_LEN. Post : D->rantai berisi salinan seq, D->panjang berisi
 * panjang dari seq.
 */
{
    D->panjang = strlen(seq);
    strncpy(D->rantai, seq, MAX_LEN);
}

/* SELEKTOR / PREDIKAT */

boolean IsStartCodon(DNA D, int idx)
/* Mengecek apakah terdapat start codon "ATG" pada posisi idx..idx+2.
 *  Pre  : D sudah terdefinisi; 0 <= idx <= D.panjang - 3.
 *  Post : Mengembalikan TRUE jika D.rantai[idx..idx+2] == "ATG", FALSE jika
 * selain itu atau idx out of range.
 */
{
    return (D.rantai[idx] == 'A') && D.rantai[idx + 1] == 'T' &&
           D.rantai[idx + 2] == 'G';
}

boolean IsStopCodon(DNA D, int idx)
/* Mengecek apakah terdapat stop codon pada posisi idx..idx+2.
 *  Stop codon: "TAA", "TAG", "TGA".
 *  Pre  : D sudah terdefinisi; 0 <= idx <= D.panjang - 3.
 *  Post : Mengembalikan TRUE jika D.rantai[idx..idx+2] adalah salah satu stop
 * codon di atas, FALSE jika selain itu atau idx out of range.
 */
{
    if (D.rantai[idx] != 'T') {
        return false;
    }
    return (D.rantai[idx + 1] == 'A' && D.rantai[idx + 2] == 'A') ||
           (D.rantai[idx + 1] == 'A' && D.rantai[idx + 2] == 'G') ||
           (D.rantai[idx + 1] == 'G' && D.rantai[idx + 2] == 'A');
}

/* OPERASI UTAMA */

DNA EkstrakProtein(DNA D)
/* Mengekstrak ORF (Open Reading Frame) pertama dari rantai DNA D.
 *  ORF didefinisikan sebagai:
 *    - Dimulai dari start codon pertama ("ATG") yang ditemukan,
 *    - Diakhiri oleh stop codon ("TAA", "TAG", atau "TGA") setelahnya,
 *    - Jarak antara start codon dan stop codon (eksklusif) habis dibagi 3,
 * sehingga terbentuk rangkaian kodon yang valid. Pre  : D sudah terdefinisi
 * dengan D.panjang > 0. Post : Mengembalikan DNA baru berisi subsequens dari
 * start codon hingga akhir stop codon (inklusif keduanya). Jika tidak ditemukan
 * ORF yang valid, mengembalikan DNA dengan rantai kosong ("") dan panjang 0.
 */
{
	DNA result;
	result.panjang = 0;
	strcpy(result.rantai, "");

	int start = -1;
	for (int i = 0; i < D.panjang - 2; i++) {
		if (start == -1) {
			if (IsStartCodon(D, i)) {
				start = i;
				i += 2;
			}
		} else {
			int len = i + 3 - start;
			if (IsStopCodon(D, i) && (len % 3 == 0)) {
				result.panjang = len;
				strncpy(result.rantai, &D.rantai[start], len);
				break;
			}
		}
	}
	return result;
}
