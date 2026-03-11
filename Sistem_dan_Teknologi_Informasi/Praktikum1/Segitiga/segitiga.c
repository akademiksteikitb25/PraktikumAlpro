#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, temp;
    scanf("%f %f %f", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Tidak valid\n");
        return 0;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Tidak valid\n");
        return 0;
    }

    if (a > b) { temp = a; a = b; b = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    if (a > b) { temp = a; a = b; b = temp; }

    int siku = fabsf(a*a + b*b - c*c) < 0.001;

    int ab_sama = fabsf(a - b) < 0.001;
    int bc_sama = fabsf(b - c) < 0.001;
    int ac_sama = fabsf(a - c) < 0.001;

    int semua_sama = ab_sama && bc_sama;
    int dua_sama = ab_sama || bc_sama || ac_sama;

    if (semua_sama) {
        printf("Segitiga Sama Sisi\n");
    } else if (siku && dua_sama) {
        printf("Segitiga Siku-Siku Sama Kaki\n");
    } else if (siku) {
        printf("Segitiga Siku-Siku\n");
    } else if (dua_sama) {
        printf("Segitiga Sama Kaki\n");
    } else {
        printf("Segitiga Sembarang\n");
    }

    return 0;
}