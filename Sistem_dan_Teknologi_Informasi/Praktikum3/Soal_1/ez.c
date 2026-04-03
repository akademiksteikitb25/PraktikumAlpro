#include <stdio.h>

int main(){
    int arr[100000];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);
        arr[i] = A;
    }

    for (int i = N-1; i >= 1; i--){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[0]);
    printf("\n");


    return 0;
}