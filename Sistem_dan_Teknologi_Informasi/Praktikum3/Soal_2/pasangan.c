#include <stdio.h>
#include <math.h>

void sortArray(int arr[], int N){
    for (int i = 1; i < N; i++){
        int x = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > x){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


int main(){
    int arr[100000];
    int N, count;

    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int A;
        scanf("%d", &A);
        arr[i] = A;
    }  

    sortArray(arr, N);
    int tot = 0;
    for (int i = 0; i < N; i++){
        tot += arr[i] * (N - i - 1);
    }

    printf("%d", tot);
    printf("\n");

    return 0;
}