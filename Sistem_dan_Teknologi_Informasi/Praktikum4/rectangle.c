#include <stdio.h>
#include "rectangle.h"

/* *** Konstruktor membentuk RECTANGLE *** */
/* *** Membentuk sebuah denah RECTANGLE dari komponen-komponen kayunya *** */
RECTANGLE MakeRectangle(float width, float height) {
    RECTANGLE make;
    Width(make) = width;
    Height(make) = height;
    return make;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** */
/* Membaca nilai panjang dan lebar dari keyboard (input dari Grunkle Stan) 
   dan membentuk RECTANGLE R berdasarkan dari nilai tersebut */
/* Komponen panjang dan lebar dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk RECTANGLE dengan panjang 1 dan lebar 2 */
void readRectangle(RECTANGLE *R) {
    float width, height; 
    scanf("%f %f", &width, &height);
    *R = MakeRectangle(width, height);
}

/* Nilai R ditulis ke layar monitor kasir dengan format "R(PanjangxLebar)"
   misalnya denah dengan panjang 1 dan lebar 2 akan ditulis
   sebagai "R(1.00x2.00)" */
void printRectangle(RECTANGLE R) {
    printf("R(%.2fx%.2f)\n", R.width, R.height);
}

/* Mengirimkan true jika width dan height dari RECTANGLE sama (Bujur sangkar sempurna / Anomali Geometris) */
boolean isSquare(RECTANGLE R) {
    return (Width(R) == Height(R));
}

/* Mengirimkan true jika width dan height dari RECTANGLE tidak sama (Normal) */
boolean isNotSquare(RECTANGLE R) {
    return (Width(R) != Height(R));
}

/* Menghitung luas RECTANGLE dengan rumus: PanjangxLebar*/
float area(RECTANGLE R) {
    return (Width(R) * Height(R));
}

/* I.S. R terdefinisi */
/* F.S. Keliling R dengan rumus 2 * (width + height) (Untuk menghitung panjang pagar pembatas) */
float perimeter(RECTANGLE R) {
    return (2 * (Width(R) + Height(R)));
}

/* R yang panjang dan lebarnya ditukar akibat efek medan gravitasi, 
   sehingga panjang sebesar lebar dan lebar sebesar panjang */
void swap(RECTANGLE *R) {
    float temp; 
    temp = Height(*R);
    Height(*R) = Width(*R);
    Width(*R) = temp;
}

/* R yang ditambah panjangnya sebesar deltaWidth dan ditambah lebarnya sebesar deltaHeight */
void add(RECTANGLE *R, float deltaWidth, float deltaHeight) {
    Width(*R) += deltaWidth;
    Height(*R) += deltaHeight;
}

/* Mengirim salinan blueprint R yang panjangnya adalah Width(R) + deltaWidth 
   dan lebarnya adalah Height(R) + deltaHeight */
RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight) {
    RECTANGLE copy;
    Width(copy) = Width(R) + deltaWidth;
    Height(copy) = Height(R) + deltaHeight;
    return copy;
}