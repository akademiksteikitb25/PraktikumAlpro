#include <stdio.h>

void cariSandi(int x, int y, char A, char B, int N) {
    for (int i = 1; i <= N; i++) {
        if (i % x == 0) {
            printf("%c", A);
        } else if (i % y == 0) {
            printf("%c", B);
        } else {
            printf("@");
        }
    }
    printf("\n");
}

int main() {
    int x, y, N;
    char A, B;

    scanf("%d %d %d", &x, &y, &N);
    scanf(" %c %c", &A, &B);

    cariSandi(x, y, A, B, N);

    return 0;
}