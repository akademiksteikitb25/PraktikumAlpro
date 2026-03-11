#include <stdio.h>

int main() {
    long long N;
    scanf("%lld", &N);

    long long nilai = N;
    int langkah = 0;
    long long maksimum = N;

    while (nilai != 1) {
        printf("%lld\n", nilai);

        if (nilai % 2 == 0) {
            nilai = nilai / 2;
        } else {
            nilai = 3 * nilai + 1;
        }

        langkah++;

        if (nilai > maksimum) {
            maksimum = nilai;
        }
    }

    printf("%lld\n", nilai);

    printf("Langkah: %d\n", langkah);
    printf("Nilai maksimum: %lld\n", maksimum);

    return 0;
}