#include <stdio.h>

int main() {
    long long Y;
    scanf("%lld", &Y);
    
    if (Y <= 0) {
        printf("Masukan tidak valid\n");
    } else if (Y % 400 == 0) {
        printf("Kabisat\n");
    } else if (Y % 100 == 0) {
        printf("Bukan Kabisat\n");
    } else if (Y % 4 == 0) {
        printf("Kabisat\n");
    } else {
        printf("Bukan Kabisat\n");
    }
    
    return 0;
}