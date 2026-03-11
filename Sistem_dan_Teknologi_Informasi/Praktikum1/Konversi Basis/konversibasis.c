#include <stdio.h>

int main() {
    int N, B;
    scanf("%d %d", &N, &B);

    if (N <= 0 || B < 2 || B > 10) {
        printf("Masukan tidak valid\n");
        return 0;
    }

    int hasil[100];
    int jumlah = 0;

    int temp = N;
    while (temp > 0) {
        hasil[jumlah] = temp % B;
        jumlah++;
        temp = temp / B;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        printf("%d", hasil[i]);
    }
    printf("\n");

    return 0;
}