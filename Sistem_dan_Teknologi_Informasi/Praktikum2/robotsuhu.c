#include <stdio.h>

// fungsi konversi suhu
float konversiSuhu(float suhu, char asal, char tujuan) {
    if (asal == tujuan) return suhu;

    // ubah dulu ke Celsius
    float c;
    if (asal == 'C') {
        c = suhu;
    } else if (asal == 'K') {
        c = suhu - 273.15;
    } else if (asal == 'F') {
        c = (suhu - 32) * 5.0 / 9.0;
    }

    // dari Celsius ke tujuan
    if (tujuan == 'C') {
        return c;
    } else if (tujuan == 'K') {
        return c + 273.15;
    } else if (tujuan == 'F') {
        return (c * 9.0 / 5.0) + 32;
    }

    return suhu;
}

int main() {
    float T;
    char Y;
    int N;

    scanf("%f %c %d", &T, &Y, &N);

    for (int i = 0; i < N; i++) {
        char cmd;
        scanf(" %c", &cmd); 

        if (cmd == 'C' || cmd == 'K' || cmd == 'F') {
            T = konversiSuhu(T, Y, cmd);
            Y = cmd;
        } else if (cmd == 'A') {
            float x;
            scanf("%f", &x);
            T += x;
        } else if (cmd == 'S') {
            float x;
            scanf("%f", &x);
            T -= x;
        }
    }

    printf("%.2f %c\n", T, Y);

    return 0;
}