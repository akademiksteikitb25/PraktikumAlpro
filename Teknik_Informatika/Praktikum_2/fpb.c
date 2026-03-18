#include <stdio.h>

int digsum(int a[], int n){
    int sum=0;
    for(int i=0; i<n; ++i){
        sum+=a[i];
    }
    return sum;
}

int divi(int a[], int n, int z){
    for(int i=0; i<n; ++i){
        if(a[i]%z){
            return 0;
        }
    }
    for(int i=0; i<n; ++i){
        a[i]/=z;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int min=9999;
    int a[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        if(a[i]<min){
            min=a[i];
        }
    }
    int ans;
    while(min>=1){
        if(!divi(a, n, min)){
            ans=digsum(a, n);
            printf("%d\n", ans);
            return 0;
        }
        min-=1;
    }
    ans=digsum(a, n);
    printf("%d\n", ans);
    return 0;
    return 0;
}
