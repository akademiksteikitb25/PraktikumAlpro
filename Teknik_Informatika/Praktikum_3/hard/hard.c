#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// #define rep(i, n) for(int i = 0; i < n; i++)
// #define float double

int get_len(int temp){
    int n = temp;
    int cnt = 1;
    while(n >= 10){
        n /= 10;
        cnt++;
    }
    return cnt;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int n; scanf("%d", &n);
    int A[n];
    int i, j;
    for(i = 0; i < n-1; i++){
        int in;
        scanf("%d ", &in);
        A[i] = in;
    }
    int in; scanf("%d", &in);
    A[n-1] = in;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(get_len(A[j]) < get_len(A[j+1])){
                swap(&A[j], &A[j+1]);
            } else if(get_len(A[j]) > get_len(A[j+1])){
                continue;
            } else{
                if(A[j] > A[j+1]) swap(&A[j], &A[j+1]);
            }
            
        }
    }
    for(i = 0; i < n-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);

    return 0;
}