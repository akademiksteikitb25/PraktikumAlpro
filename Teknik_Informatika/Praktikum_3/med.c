#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// #define rep(i, n) for(int i = 0; i < n; i++)
// #define float double

int min(int a, int b){
    if(a < b) return a;
    return b;
}

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
    int i, j;
    int ok = 0;
    for(i = 0; i < n-1; i++){
        int in;
        scanf("%d ", &in);
        A[i] = in;
        if(in == x) ok = 1;
    }
    int in; scanf("%d", &in);
    if(in == x) ok = 1;
    A[n-1] = in;
    if(ok) printf("%d ", x);
    for(i = 0; i < n-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);

    return 0;
}