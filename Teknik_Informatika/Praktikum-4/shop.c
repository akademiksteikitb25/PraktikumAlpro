#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */
typedef struct {
    char id[100];
    char nama[100];
    int harga;
    int total_pdpt;
    int ada_transaksi;
} item;

int main() {
    init();
    
    item katalog[100];
    int jumlah = 0;

    FILE *file_katalog;
    file_katalog = fopen("katalog.txt", "r");
    if(file_katalog == NULL) return 1;

    while (1) {
        char id[100], nama[100];
        int harga;

        if(fscanf(file_katalog, "%s", id) != 1) break;
        if(id[0] == '.') break;

        fscanf(file_katalog, "%s %d", nama, &harga);

        strcpy(katalog[jumlah].id, id);
        strcpy(katalog[jumlah].nama, nama);
        katalog[jumlah].harga = harga;
        katalog[jumlah].total_pdpt = 0;
        katalog[jumlah].ada_transaksi = 0;
        jumlah++;
    }

    fclose(file_katalog);

    FILE *file_transaksi = fopen("transaksi.txt", "r");
    if (file_transaksi == NULL) return 1;

    while (1) {
        char id[10];
        int jmlh;

        if (fscanf(file_transaksi, "%s", id) != 1) break;
        if (id[0] == '.') break;

        fscanf(file_transaksi, "%d", &jmlh);

        for (int i = 0; i < jumlah; i++) {
            if (strcmp(katalog[i].id, id) == 0) {
                katalog[i].total_pdpt += katalog[i].harga * jmlh;
                katalog[i].ada_transaksi = 1;
                break;
            }
        }
    }

    fclose(file_transaksi);

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (strcmp(katalog[i].id, katalog[j].id) > 0) {
                item temp = katalog[i];
                katalog[i] = katalog[j];
                katalog[j] = temp;
            }
        }
    }

    long long total_keseluruhan = 0;

    for (int i = 0; i < jumlah; i++) {
        if (katalog[i].ada_transaksi) {
            printf("%s %lld\n", katalog[i].nama, katalog[i].total_pdpt);
            total_keseluruhan += katalog[i].total_pdpt;
        }
    }

    printf("TOTAL %lld\n", total_keseluruhan);

    return 0;
}