#include <stdio.h>
#include <stdlib.h>

long long countDig(long long x){
    if (x == 0) return 1;
    long long count = 0;
    while (x > 0){
        count++;
        x /= 10;
    }
    return count;
}


int main(){
    long long N;
    scanf("%lld", &N);
    long long arr[N];

    for (long long i = 0; i < N; i++){
        long long A;
        scanf("%lld", &A);
        arr[i] = A;
    }

    for (long long i = 0; i < N-1; i++){
        for (long long j = 0; j < N - i - 1; j++){
            long long left = countDig(arr[j]);
            long long right = countDig(arr[j+1]);
            if (left < right || (left == right && arr[j] > arr[j+1])){
                long long temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    
    for(long long i = 0; i < N; i++){
        if (i > 0) printf(" ");
        printf("%lld", arr[i]);
    }
    printf("\n");







    return 0;
}