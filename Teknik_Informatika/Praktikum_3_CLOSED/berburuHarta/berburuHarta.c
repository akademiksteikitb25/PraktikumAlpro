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
    rep(i, n-1){
        int x;
        scanf("%d ", &x);
        A[i] = x;
    }
    int x; scanf("%d", &x);
    A[n-1] = x;
    int target = n+1;
    rep(i, n){
        int vis[205];
        memset(vis, 0, sizeof vis);
        int cur = i;
        int cnt = 0;
        int ok = 0;
        while(!vis[cur]){
            // printf("%d ", cur);
            cnt++;
            vis[cur] = 1;
            if(A[cur] == target){
                ok = 1;
                break;
            }
            cur = A[cur]-1;
        }
        if(ok) printf("%d\n", cnt);
            else printf("-1\n");
    }

    return 0;
}