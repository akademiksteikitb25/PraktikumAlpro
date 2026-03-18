#include <stdio.h>

// Menghitung jumlah digit dari suatu bilangan
int hitungDigit(int N) {
    int jumlah = 0;
    while (N > 0) {
        jumlah += N % 10;
        N /= 10;
    }
    return jumlah;
}

// Menghitung banyaknya digit
int hitungJumlahDigit(int N) {
    int count = 0;
    if (N == 0) return 1;
    while (N > 0) {
        count++;
        N /= 10;
    }
    return count;
}

void cariKode(int N) {
    int sum = hitungDigit(N);

    // gabung sum di depan N
    int temp = N;
    int digitN = hitungJumlahDigit(N);
    int hasil2 = sum;

    for (int i = 0; i < digitN; i++) {
        hasil2 *= 10;
    }
    hasil2 += temp;

    int jumlahDigit = hitungJumlahDigit(hasil2);

    // gabung jumlahDigit di depan hasil2
    int hasil3 = jumlahDigit;
    int digitHasil2 = hitungJumlahDigit(hasil2);

    for (int i = 0; i < digitHasil2; i++) {
        hasil3 *= 10;
    }
    hasil3 += hasil2;

    printf("%d\n", hasil3);
}

int main() {
    int N;
    scanf("%d", &N);

    cariKode(N);

    return 0;
}