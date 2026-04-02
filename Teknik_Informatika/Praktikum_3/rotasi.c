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

    int n, q; scanf("%d", &n);
    int A[n];
    int i, j;
    for(i = 0; i < n-1; i++){
        int in;
        scanf("%d ", &in);
        A[i] = in;
    }
    int in; scanf("%d", &in);
    A[n-1] = in;
    // for(i = 0; i < n; i++){
    //     printf("%d ", A[i]);
    // }
    scanf("%d\n", &q);
    // printf("%d\n", q);
    int idx = 0;
    // char C; scanf("%c", &C);
    // printf("%c", C);
    while(q--){
        char C; scanf("%c ", &C);
        int x;
        scanf("%d\n", &x);
        // printf("%c %d ", C, x);
        if(C == 'L'){
            x %= n;
            idx += x;
        } else{
            x %= n;
            idx -= x;
        }
        idx %= n;
        if(idx < 0) idx += n;
        // printf("%d\n", idx);
    }
    if(idx == 0){
        for(i = 0; i < n-1; i++){
            printf("%d ", A[i]);
        }
        printf("%d\n", A[n-1]);
        return 0;
    }
    for(i = idx; i < n; i++){
        printf("%d ", A[i]);
    }
    for(i = 0; i < idx-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[idx-1]);

    return 0;
}