// Program Mebel 
// Program untuk menggambar pola huruf "M"

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int lebar = (2 * N) - 1;
    if (N < 3 || N > 100) {
        printf("Masukan tidak valid\n");
    }
    return 0;
}