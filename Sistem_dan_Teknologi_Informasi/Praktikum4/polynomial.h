#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEGREE 100 /* Batas maksimum derajat anomali portal */

/* ADT POLYNOMIAL (Sandi Portal Dimensi Lebaran)
   ---------------
   Representasi polinomial (sandi energi) dalam bentuk:
      P(x) = a_n * x^n + a_(n-1) * x^(n-1) + ... + a_1 * x + a_0
   Dimana:
     - 'degree' merupakan derajat tertinggi polinomial (n) yang memiliki koefisien bukan nol.
     - 'coef' adalah array yang menyimpan koefisien (takaran energi/ketupat) untuk masing-masing pangkat,
       yaitu coef[i] menyimpan koefisien untuk x^i.
*/
typedef struct
{
    int degree;               /* Derajat polinomial, yaitu pangkat anomali tertinggi yang aktif */
    int coef[MAX_DEGREE + 1]; /* Array koefisien dari x^0 hingga x^(degree). coef[i] merupakan koefisien a_i */
} Polynomial;

/* --- Konstruktor dan Inisialisasi --- */
/*
   Fungsi: CreatePolynomial
   Deskripsi:
     Menginisialisasi sebuah polinomial P dengan derajat tertentu (menyiapkan wadah kosong).
     Semua koefisien pada polinomial diinisialisasi ke nilai 0 (belum ada energi yang dimasukkan).
   I.S. (Initial State): P belum terdefinisi
   F.S. (Final State): P terdefinisi dengan nilai degree yang diberikan, dan seluruh koefisien bernilai 0.
   Contoh:
     Polynomial P;
     CreatePolynomial(&P, 3);
     // Hasil: P.degree = 3, dan P.coef[0..3] semuanya bernilai 0.
*/
void CreatePolynomial(Polynomial *P, int degree);

/* --- Input/Output Polinomial --- */
/*
   Fungsi: ReadPolynomial
   Deskripsi:
     Membaca input sandi polinomial dari Grunkle Ford. Proses input dilakukan dengan langkah berikut:
       1. Membaca nilai derajat polinomial (tingkat bahaya dimensi).
          Nilai derajat menentukan berapa banyak suku (pangkat) yang akan dibaca, dari 0 hingga derajat tersebut.
       2. Membaca koefisien (dalam bentuk integer) untuk setiap pangkat dari 0 hingga derajat yang telah ditentukan.
   I.S.: P sembarang.
   F.S.: P terdefinisi sesuai dengan input pengguna.
*/
void ReadPolynomial(Polynomial *P);

/*
   Fungsi: WritePolynomial
   Deskripsi:
     Menampilkan polinomial ke layar monitor portal dalam format standar, misalnya:
       3x^3 + 2x^2 - x + 5
     Polinomial dicetak dari pangkat tertinggi ke pangkat 0. Koefisien dengan nilai 0 dilewati
     agar tampilan output lebih rapi dan tidak membingungkan Dipper.
   I.S.: P terdefinisi.
   F.S.: Polinomial ditampilkan pada layar.
*/
void WritePolynomial(Polynomial P);

/* --- Operasi Aritmatika Polinomial --- */
/*
   Fungsi: AddPolynomial
   Deskripsi:
     Menjumlahkan dua buah sandi polinomial P1 dan P2 (Interferensi Energi). 
     Proses penjumlahan dilakukan dengan menjumlahkan koefisien pada pangkat yang sama. 
     Jika salah satu polinomial memiliki derajat yang lebih rendah, koefisien yang tidak ada dianggap sebagai 0.
   I.S.: P1 dan P2 terdefinisi.
   F.S.: Mengembalikan polinomial hasil penjumlahan P1 + P2, dengan derajat disesuaikan berdasarkan
         koefisien tertinggi yang bukan nol.
*/
Polynomial AddPolynomial(Polynomial P1, Polynomial P2);

/*
   Fungsi: MultiplyPolynomial
   Deskripsi:
     Mengalikan dua buah polinomial P1 dan P2 (Reaksi Berantai). Setiap koefisien pada P1 dikalikan 
     dengan setiap koefisien pada P2, dan hasil perkalian ditempatkan pada pangkat yang merupakan 
     penjumlahan indeks kedua koefisien yang dikalikan.
   I.S.: P1 dan P2 terdefinisi.
   F.S.: Mengembalikan polinomial hasil perkalian P1 * P2.
*/
Polynomial MultiplyPolynomial(Polynomial P1, Polynomial P2);

/*
   Fungsi: EvaluatePolynomial
   Deskripsi:
     Mengevaluasi nilai polinomial P untuk suatu nilai x tertentu (Uji Coba Stabilitas Portal).
     Karena koefisien bertipe integer dan x juga merupakan integer,
     maka hasil evaluasi juga berupa integer.
   I.S.: P terdefinisi dan x merupakan bilangan integer.
   F.S.: Mengembalikan nilai hasil evaluasi P(x) dalam bentuk integer.
*/
int EvaluatePolynomial(Polynomial P, int x);

/*
   Fungsi: DerivativePolynomial
   Deskripsi:
     Menghitung turunan pertama dari polinomial P (Penyusutan Energi Seiring Waktu). 
     Jika polinomial didefinisikan sebagai
       P(x) = a_n*x^n + ... + a_1*x + a_0,
     maka turunan P'(x) adalah:
       P'(x) = n*a_n*x^(n-1) + (n-1)*a_(n-1)*x^(n-2) + ... + 1*a_1.
     Apabila P merupakan polinomial konstan (degree 0), maka turunan yang dihasilkan adalah 0.
   I.S.: P terdefinisi.
   F.S.: Mengembalikan polinomial yang merupakan turunan pertama dari P.
*/
Polynomial DerivativePolynomial(Polynomial P);

#endif