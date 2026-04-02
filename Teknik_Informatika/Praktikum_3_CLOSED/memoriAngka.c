#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i, n) for(int i = 0; i < n; i++)
// #define float double

int main(){

    int n; scanf("%d", &n);
    int A[n];
    rep(i, n){
        int x;
        scanf("%d", &x);
        A[i] = x;
        int ok = 0;
        for(int j = i-1; j >= 0; j--){
            if(A[j] == x){
                printf("LAMA\n");
                ok = 1;
                break;
            }
        }
        if(!ok) printf("BARU\n");
    }

    return 0;
}