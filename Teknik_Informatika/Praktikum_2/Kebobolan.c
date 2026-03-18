#include <stdio.h>

int lower(char c){
    if((c - 'a') >= 0 && (c - 'a') <= 25){
        return 1;
    }
    return 0;
}

int upper(char c){
    if((c - 'A') >= 0 && (c - 'A') <= 25){
        return 1;
    }
    return 0;
}

int numb(char c){
    if(!lower(c) && !upper(c)){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    int u=0;
    int l=0;
    int no=0;
    scanf("%d", &n);
    char x;
    for(int i=0; i<=n*2-1; i++){
        scanf("%c", &x);
        if(i%2){ //Skip input spasi
            printf("%c", x);
            u += upper(x);
            l += lower(x);
            no += numb(x);
        }
    }

    if(u && l && no && n>=8){
        printf("KUAT");
    }else{
        printf("LEMAH");
    }
    printf("\n");

    return 0;
}
