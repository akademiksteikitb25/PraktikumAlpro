#include <stdio.h>
#include <stdlib.h>

void shiftRight(int arr[], int N, int K){
    K %= N;
    while (K--){
        int last = arr[N-1];
        for (int i = N-1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
}

void shiftLeft(int arr[], int N, int K){
    K %= N;
    while (K--){
        int first = arr[0];
        for (int i = 0 ; i < N - 1; i++){
            arr[i] = arr[i+1];
        }
        arr[N-1] = first;
    }
}



int main(){
    int N,Q;
    scanf("%d", &N);
    int arr[N];

    for(int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);
        arr[i] = A;
    }

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++){
        char C;
        int K;
        scanf(" %c %d", &C, &K);
        if (C == 'R'){
            shiftRight(arr, N, K);
        }
        else{
            shiftLeft(arr,N,K);
        }

    }

    for (int i = 0; i < N-1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[N-1]);
    printf("\n");





    return 0;
}