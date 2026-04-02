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

int main(){

    int n; scanf("%d", &n);
    int A[n];
    rep(i, n-1){
        int x;
        scanf("%d ", &x);
        A[i] = x;
    }
    int x; scanf("%d", &x);
    A[n-1] = x;
    int tot = 0;
    int maxim = 0;
    rep(i, n){
        tot += A[i];
        maxim = max(maxim, A[i]);
    }
    if(tot % 2){
        printf("-1\n");
        return 0;
    }
    tot -= maxim;
    if(tot < maxim){
        printf("-1\n");
        return 0;
    }
    tot += maxim;
    printf("%d\n", (tot/2));

    return 0;
}