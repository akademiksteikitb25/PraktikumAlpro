#include <stdio.h>

/* Program jaraktempuh */
/* Menghitung jarak yang ditempuh berdasarkan masukan kecepatan dan waktu */

/* KAMUS */
float v;
int t;

/* ALGORITMA */
int main()
{
    scanf("%f%d", &v, &t);
    printf("%.2f\n", v*t);
    return 0;
}