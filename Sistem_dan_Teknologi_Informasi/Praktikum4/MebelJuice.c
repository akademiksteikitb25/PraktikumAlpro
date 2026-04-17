#include <stdio.h>
#include "MebelJuice.h"

/* Constructor minuman */
/*
 * Membuat pesanan minuman berdasarkan:
 * - nama minuman
 * - tipe suhu (DINGIN, NORMAL, HANGAT)
 * - tipe gula (LOW, MEDIUM, HIGH)
 * - jumlah es (gram)
 * - jumlah glitter (gram)
 * - jumlah permen dinosaurus
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Minuman buatMinuman(char *nama, Suhu suhu, LevelGula levelGula, int es, int glitter, int dino) {
    Minuman minum; 
    strcpy(minum.nama, nama);
    minum.suhu = suhu;
    minum.levelGula = levelGula;
    minum.es = es; 
    minum.topping.glitter = glitter;
    minum.topping.dino = dino;
    return minum;
}

/**
 * Menghitung volume minuman dalam gram:
 * volume = 200 + berat es + (jumlah dinosaurus * 5) + berat glitter
 */
float hitungVolume(Minuman m) {
    return (200 + (m.es) + (m.topping.dino * 5) + m.topping.glitter);
}

/**
 * Menghitung kalori minuman:
 * total = base + topping.dino*10 + glitter*2
 * 
 * dengan base memiliki kalori:
 * LOW    = 20
 * MEDIUM = 40
 * HIGH   = 60
 */
float hitungKalori(Minuman m) {
    int base = 0;
    switch (m.levelGula) {
        case 0: base = 20; break;
        case 1: base = 40; break;
        case 2: base = 60; break;
    }

    return (base + (m.topping.dino * 10) + (m.topping.glitter * 2));
}

/* Constructor pelanggan */
/*
 * Membuat pelanggan berdasarkan:
 * - nama pelanggan
 * - id pelanggan
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Pelanggan buatPelanggan(char *nama, int id) {
    Pelanggan customer;
    strcpy(customer.nama, nama);
    customer.id = id;
    return customer;
}

/* Constructor pesanan */
/*
 * Membuat pesanan minuman dengan memasukkan detail:
 * - identitas pelanggan
 * - minuman pelanggan
 * - volume minuman
 * - kalori minuman 
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(warga.pekerjaan, pekerjaan);
*/
Pesanan buatPesanan(Pelanggan pelanggan, Minuman m) {
    Pesanan order; 
    order.pelanggan = pelanggan;
    order.minuman = m;
    order.volumeGelas = hitungVolume(m);
    order.kaloriGelas = hitungKalori(m);
    return order;
}

/**
 * Menampilkan detail pesanan dengan format:
 * "Nama Pelanggan: <nama pelanggan>"
 * "ID Pelanggan: <id>"
 * "Minuman: <nama minuman"
 * "Suhu: <suhu>"
 * "Level Gula: <gula>"
 * "Es: <berat gula> gram"
 * "Glitter: %d gram"
 * "Dino: <jumlah dino>"
 * "Volume: <total volume dengan dua angka desimal> ml"
 * "Kalori: <total kalori dengan dua angka desimal> kkal"
 */
void tampilkanPesanan(Pesanan p) {
    printf("Nama Pelanggan: %s\n", p.pelanggan.nama);
    printf("ID Pelanggan: %d\n", p.pelanggan.id);
    printf("Minuman: %s\n", p.minuman.nama);

    char bufferSuhu[MAX_STR];
    suhuToString(p.minuman.suhu, bufferSuhu);
    printf("Suhu: %s\n", bufferSuhu);

    char bufferGula[MAX_STR];
    levelGulaToString(p.minuman.levelGula, bufferGula);
    printf("Level Gula: %s\n", bufferGula);

    printf("Es: %d gram\n", p.minuman.es);
    printf("Glitter: %d gram\n", p.minuman.topping.glitter);
    printf("Dino: %d\n", p.minuman.topping.dino);
    printf("Volume: %.2f ml\n", p.volumeGelas);
    printf("Kalori: %.2f kkal\n", p.kaloriGelas);
}

/**
 * Membuat daftar pesanan kosong
 */
void initList(ListPesanan *l) {
    l->jumlah = 0;
}

/**
 * Return true jika daftar pesanan kosong
 */
int isEmpty(ListPesanan l) {
    return (l.jumlah == 0);
}

/**
 * Return true jika daftar pesanan penuh (MAX_PESANAN)
 */
int isFull(ListPesanan l) {
    return (l.jumlah == MAX_PESANAN);
}

/**
 * Menambahkan pesanan ke daftar pesanan
 * Pesanan tidak ditambahkan jika daftar pesanan penuh
 */
void tambahPesanan(ListPesanan *l, Pesanan p) {
    if (!isFull(*l)) {
        l->data[l->jumlah] = p;
        l->jumlah++;
    }
}

/**
 * Menghapus pesanan terakhir dari daftar pesanan
 * Jika daftar kosong, tidak melakukan apa-apa
 */
void hapusPesanan(ListPesanan *l) {
    if (!isEmpty(*l)) {
        l->jumlah--;
    }
}

/**
 * Menampilkan detail seluruh pesanan yang ada
 */
void tampilkanSemuaPesanan(ListPesanan l) {
    for (int i = 0; i < l.jumlah; i++) {
        tampilkanPesanan(l.data[i]);
        if (i < l.jumlah - 1) printf("\n");
    }
}

/* UTILITY */
/* Implementasi fungsi di bawah ini untuk mengubah enum menjadi string */

/* Return nilai enum suhu dalam bentuk string ke buffer*/
void suhuToString(Suhu s, char *buffer) {
    switch(s) {
        case DINGIN: strcpy(buffer, "DINGIN"); break;
        case NORMAL: strcpy(buffer, "NORMAL"); break;
        case HANGAT: strcpy(buffer, "HANGAT"); break;
    }
}

/* Return nilai enum gula dalam bentuk string ke buffer*/
void levelGulaToString(LevelGula g, char *buffer) {
    switch(g) {
        case LOW: strcpy(buffer, "LOW"); break;
        case MEDIUM: strcpy(buffer, "MEDIUM"); break;
        case HIGH: strcpy(buffer, "HIGH"); break;
    }
}