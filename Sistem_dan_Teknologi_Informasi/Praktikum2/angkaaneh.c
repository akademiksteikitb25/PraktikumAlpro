#include <stdio.h>
#include <stdbool.h>

int faktorial(int n) {
    int hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

bool cekAngkaAneh(int x) {
    int temp = x;
    int jumlah = 0;

    while (temp > 0) {
        int digit = temp % 10;
        jumlah += faktorial(digit);
        temp /= 10;
    }

    return (jumlah == x);
}

int main() {
    int N;
    scanf("%d", &N);

    int F;
    for (int i = 0; i < N; i++) {
        scanf("%d", &F);

        if (cekAngkaAneh(F)) {
            printf("BAHAYA\n");
        } else {
            printf("AMAN\n");
        }
    }

    return 0;
}