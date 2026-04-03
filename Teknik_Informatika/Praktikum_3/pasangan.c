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
    int tot = 0;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            tot += min(A[i], A[j]);
        }
    }
    printf("%d\n", tot);

    return 0;
}