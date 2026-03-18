#include <stdio.h>
#include <math.h>

//Rada brute force

float dist(float x, float y, float a, float b){ //Pythagoras
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

float grad(float a, float b, float c, float d){ //Gradien
    return (b-d)/(a-c);
}

float poty(float a, float b, float m, float x){ //Ordinat Titik Potong
    return m*(x-a) + b;
}

float potx(float a, float b, float c, float d, float m1, float m2){ //Absis Titik Potong
    return (d - b + m1*a - m2*c)/(m1 - m2);
}

float dist1(float a, float b){//Jarak biasa
    return a-b;
}

int main(){
    float x_A, y_A, x_B, y_B, x_C, y_C, x_D, y_D, x_E, y_E;
    scanf("%f %f %f %f %f %f %f %f %f %f", &x_A, &y_A, &x_B, &y_B, &x_C, &y_C, &x_D, &y_D, &x_E, &y_E);

    float x1, y1, m1a, m1b;
    //Kasus AB CD
    if(dist1(x_A, x_B)==0 || dist1(x_C, x_D)==0){//Kasus Garis Tegak (|)
        if(x_A==x_B){
            x1 = x_A;
            m1b = grad(x_C,y_C, x_D, y_D);
            y1 = poty(x_C, y_C, m1b, x1);
        }else{
            x1=x_C;
            m1a = grad(x_A,y_A, x_B, y_B);
            y1 = poty(x_A, y_A, m1a, x1);
        }
    }else{
        m1a = grad(x_A,y_A, x_B, y_B);
        m1b = grad(x_C,y_C, x_D, y_D);
        x1=potx(x_B, y_B, x_D, y_D, m1a, m1b);
        y1=poty(x_A, y_A, m1a, x1);
    }
    float ans=dist(x1, y1, x_E, y_E);

    //Kasus AD BC
    if(dist1(x_A, x_D)==0 || dist1(x_B, x_C)==0){
        if(x_A==x_D){
            x1 = x_A;
            m1b = grad(x_B,y_B, x_C, y_C);
            y1 = poty(x_B, y_B, m1b, x1);
        }else{
            x1=x_C;
            m1a = grad(x_A,y_A, x_D, y_D);
            y1 = poty(x_A, y_A, m1a, x1);
        }
    }else{
        m1a = grad(x_A,y_A, x_D, y_D);
        m1b = grad(x_B,y_B, x_C, y_C);
        x1=potx(x_D, y_D, x_C, y_C, m1a, m1b);
        y1=poty(x_A, y_A, m1a, x1);
    }
    ans=fmin(ans,dist(x1, y1, x_E, y_E));

    //Kasus AC BD
    if(dist1(x_A, x_C)==0 || dist1(x_B, x_D)==0){
        if(x_A==x_C){
            x1 = x_A;
            m1b = grad(x_B,y_B, x_D, y_D);
            y1 = poty(x_B, y_B, m1b, x1);
        }else{
            x1=x_C;
            m1a = grad(x_A,y_A, x_C, y_C);
            y1 = poty(x_A, y_A, m1a, x1);
        }
    }else{
        m1a = grad(x_A,y_A, x_C, y_C);
        m1b = grad(x_B,y_B, x_D, y_D);
        x1=potx(x_C, y_C, x_D, y_D, m1a, m1b);
        y1=poty(x_A, y_A, m1a, x1);
    }
    ans=fmin(ans,dist(x1, y1, x_E, y_E));

    printf("%.2f\n", ans);
    return 0;
}
