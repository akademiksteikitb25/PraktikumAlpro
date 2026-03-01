#include <stdio.h>

/* Program luaslingkaran */
/* Menghitung luas lingkaran dari masukan jari-jari*/

/* KAMUS */
float r;
const float PI = 3.1415f;

/* ALGORITMA */
int main()
{
    scanf("%f", &r);
    printf("%f\n", PI * r *r);
    return 0;
}