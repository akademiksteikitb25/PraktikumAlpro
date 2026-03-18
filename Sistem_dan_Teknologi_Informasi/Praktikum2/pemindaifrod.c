#include <stdio.h>

int isPrime(int p) {
    if (p < 2) return 0;
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) return 0;
    }
    return 1;
}

int main() {
    int P, D;
    int count = 0;

    scanf("%d %d", &P, &D);

    for (int i = P - D; i <= P + D; i++) {
        if (isPrime(i)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}