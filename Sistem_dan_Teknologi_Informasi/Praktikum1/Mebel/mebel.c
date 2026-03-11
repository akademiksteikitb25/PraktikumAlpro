#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 3 || n > 100) {
        printf("Masukan tidak valid\n");
        return 0;
    }
    
    int width = 2 * n - 1;
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == i || j == width - i || j == width - 1) {
                printf("M");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}