#ifndef MEBELJUICE_H
#define MEBELJUICE_H

#include <stdio.h>
#include <string.h>

/* Konstanta */
#define MAX_STR 100
#define MAX_PESANAN 50

/* Enum suhu minuman */
typedef enum {
    DINGIN,
    NORMAL,
    HANGAT
} Suhu;

/* Enum kadar gula */
typedef enum {
    LOW,
    MEDIUM,
    HIGH
} LevelGula;

/* Tipe data topping */
typedef struct {
    int glitter;        // gram glitter
    int dino;           // jumlah permen dinosaurus
} Topping;

/* Tipe data minuman */
typedef struct {
    char nama[MAX_STR];     // nama minuman (contoh: "Soda")
    Suhu suhu;              // preferensi suhu
    LevelGula levelGula;    // preferensi gula
    int es;                 // gram es
    Topping topping;        // preferensi topping
} Minuman;

/* Tipe data pelanggan */
typedef struct {
    char nama[MAX_STR];     // nama pelanggan
    int id;
} Pelanggan;

/* Tipe data pesanan */
typedef struct {
    Pelanggan pelanggan;    // data pelanggan
    Minuman minuman;        // data minuman
    float volumeGelas;      // preferensi volume      
    float kaloriGelas;      // preferensi kalori
} Pesanan;

/* Tipe data daftar pesanan */
typedef struct {
    Pesanan data[MAX_PESANAN];      // data pesanan
    int jumlah;                     // jumlah minuman yang dipesan
} ListPesanan;

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
Minuman buatMinuman(char *nama, Suhu suhu, LevelGula levelGula, int es, int glitter, int dino);

/**
 * Menghitung volume minuman dalam gram:
 * volume = 200 + berat es + (jumlah dinosaurus * 5) + berat glitter
 */
float hitungVolume(Minuman m);

/**
 * Menghitung kalori minuman:
 * total = base + topping.dino*10 + glitter*2
 * 
 * dengan base memiliki kalori:
 * LOW    = 20
 * MEDIUM = 40
 * HIGH   = 60
 */
float hitungKalori(Minuman m);

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
Pelanggan buatPelanggan(char *nama, int id);

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
Pesanan buatPesanan(Pelanggan pelanggan, Minuman m);

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
void tampilkanPesanan(Pesanan p);

/**
 * Membuat daftar pesanan kosong
 */
void initList(ListPesanan *l);

/**
 * Return true jika daftar pesanan kosong
 */
int isEmpty(ListPesanan l);

/**
 * Return true jika daftar pesanan penuh (MAX_PESANAN)
 */
int isFull(ListPesanan l);

/**
 * Menambahkan pesanan ke daftar pesanan
 * Pesanan tidak ditambahkan jika daftar pesanan penuh
 */
void tambahPesanan(ListPesanan *l, Pesanan p);

/**
 * Menghapus pesanan terakhir dari daftar pesanan
 * Jika daftar kosong, tidak melakukan apa-apa
 */
void hapusPesanan(ListPesanan *l);

/**
 * Menampilkan detail seluruh pesanan yang ada
 */
void tampilkanSemuaPesanan(ListPesanan l);

/* UTILITY */
/* Implementasi fungsi di bawah ini untuk mengubah enum menjadi string */

/* Return nilai enum suhu dalam bentuk string ke buffer*/
void suhuToString(Suhu s, char *buffer);

/* Return nilai enum gula dalam bentuk string ke buffer*/
void levelGulaToString(LevelGula g, char *buffer);

#endif