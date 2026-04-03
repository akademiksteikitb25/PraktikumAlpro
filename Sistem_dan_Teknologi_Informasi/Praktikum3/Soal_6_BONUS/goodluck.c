#include <stdio.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++){
        int now = i;
        for (int j = 0; j < K; j++){
            now = arr[now];
        }
        if (i > 0) printf(" ");
        printf("%d", now);
    }
    printf("\n");

    return 0;
}