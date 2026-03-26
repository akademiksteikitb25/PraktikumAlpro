#include <stdio.h>

int isPrime(int x){
    if(x<=1){
        return 0;
    }

    for(int i=2; i*i<=x; ++i){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int cekDigit(int x){
    int sum=0;
    while(x){
        sum+=x%10;
        if(!isPrime(x%10)){
            return 0;
        }
        x/=10;
    }
    int p = 1;
    p+=isPrime(sum);

    return p;
}

int main(){
    int x;
    int cnt=0;
    scanf("%d", &x);
    cnt = isPrime(x) + cekDigit(x);
    if(cnt>=3){
        printf("1");
    }else{
        printf("0");
    }

    printf("\n");
    return 0;
}
