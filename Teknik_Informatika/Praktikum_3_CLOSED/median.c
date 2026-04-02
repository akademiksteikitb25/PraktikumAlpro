#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i, n) for(int i = 0; i < n; i++)
// #define float double

int max(int a, int b){
    if(a > b) return a;
    return b;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int n, x; scanf("%d %d", &n, &x);
    int A[n];
    rep(i, n-1){
        int in;
        scanf("%d ", &in);
        A[i] = in;
    }
    int in; scanf("%d", &in);
    A[n-1] = in;
    rep(i, n-1){
        rep(j, n-i-1){
            if(A[j] > A[j+1]) swap(&A[j], &A[j + 1]);
        }
    }
    int need = 0;
    rep(i, n){
        if(i < n/2){
            if(A[i] > x) need += abs(x - A[i]);
        } else if(i > n/2){
            if(A[i] < x) need += abs(x - A[i]);
        } else{
            if(A[i] != x) need += abs(x - A[i]);
        }
    }
    printf("%d\n", need);

    return 0;
}