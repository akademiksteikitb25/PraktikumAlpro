#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();

    FILE *file_kunci;

    char idx[256];
    for(int i = 0; i<256; i++) {
        idx[i] = (char)i;
    }

    file_kunci = fopen("kunci.txt", "r");
    if (file_kunci == NULL) return 1;

    char plain, cip;

    while (fscanf(file_kunci, " %c %c", &plain, &cip) == 2) {
        idx[cip] = plain;
    }

    fclose(file_kunci);

    FILE *file_cipher;

    file_cipher = fopen("ciphertext.txt", "r");
    if (file_cipher == NULL) return 1;

    int cel;

    while ((cel = fgetc(file_cipher)) != EOF) {
        if (cel == '.') break;
        else if (cel == ' ') printf(" ");
        else if (cel >= 'a' && cel <= 'z') printf("%c", idx[cel]);
    }

    printf("\n");

    return 0;
}
