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

int dist(int x1, int x2, int y1, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){

    int n; scanf("%d", &n);
    int X[n], Y[n];
    rep(i, n){
        int x, y;
        scanf("%d %d", &x, &y);
        X[i] = x;
        Y[i] = y;
    }
    int maxim = 0;
    rep(i, n){
        rep(j, n){
            int x1 = X[i], y1 = Y[i], x2 = X[j], y2 = Y[j];
            maxim = max(maxim, dist(x1, x2, y1, y2));
        }
    }
    printf("%d\n", maxim);

    return 0;
}