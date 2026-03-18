#include <stdio.h>

int fungsi(int x){
    return x*x + 5*x + 7;
}

int gungsi(int x){
    return x*x*x*x + 2*x + 1;
}

int main(){
    int x;
    scanf("%d", &x);
    int ans=fungsi(gungsi(x));
    printf("%d\n", ans);
}
