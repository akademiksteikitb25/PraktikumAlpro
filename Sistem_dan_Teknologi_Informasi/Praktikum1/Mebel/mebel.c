// Program Mebel 
// Program untuk menggambar pola huruf "M"

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 3 || N > 100) {
        printf("Masukan tidak valid\n");
        return 0;
    }

    int lebar = 2 * N - 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < lebar; j++) {

            if (j == 0 || j == lebar - 1 || j == i || j == lebar - 1 - i) {
                printf("M");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }

    return 0;
}
