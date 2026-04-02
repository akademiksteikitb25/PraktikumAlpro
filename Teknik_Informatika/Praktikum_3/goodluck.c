#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// #define rep(i, n) for(int i = 0; i < n; i++)
// #define float double
#define BIT 31

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int max(int a, int b){
    if(a > b) return a;
    return b;
}

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

    int n, k; scanf("%d %d", &n, &k);
    int bit[BIT][n+5];
    int i, j;
    for(i = 0; i < n-1; i++){
        int in;
        scanf("%d ", &in);
        bit[0][i] = in;
    }
    int in; scanf("%d", &in);
    bit[0][n-1] = in;
    for(i = 1; i < BIT; i++){
        for(j = 0; j < n; j++){
            bit[i][j] = bit[i-1][bit[i-1][j]];
        }
    }
    for(i = 0; i < n; i++){
        int cur = i;
        for(j = 0; j < BIT; j++){
            if((k >> j) & 1){
                cur = bit[j][cur];
            }
        }
        if(i != n-1) printf("%d ", cur);
            else printf("%d\n", cur);
    }

    return 0;
}