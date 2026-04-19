#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// #define rep(i, n) for(int i = 0; i < n; i++)
// #define float double

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
    for(j = n-1; j > 0; j--){
        printf("%d ", A[j]);
    }
    printf("%d\n", A[0]);

    return 0;
}