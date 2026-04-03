#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100000];
    int N, X;
    int yes = 0;
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++){
        int A;
        scanf("%d",&A);
        if (A == X) yes = 1;
        arr[i] = A;
    }

    if (yes == 1){
        int *new = (int*) malloc((N+1) * sizeof(int));
        new[0] = X;
        for (int i = 1; i <= N; i++){
            new[i] = arr[i-1];
        }
        for (int i = 0; i < N; i++){
            printf("%d ", new[i]);
        }
        printf("%d", new[N]);
        printf("\n");
    }
    else{
        for (int i = 0; i < N-1; i++){
            printf("%d ", arr[i]);
        }
        printf("%d", arr[N-1]);
        printf("\n");
    }

    return 0;
}