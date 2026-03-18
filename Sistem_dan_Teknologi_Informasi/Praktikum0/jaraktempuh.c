#include <stdio.h>

int main() {
    float v, jarak;
    int t;
    
    scanf("%f", &v);
    scanf("%d", &t);
    
    jarak = v * t;
    
    printf("%.2f\n", jarak);
    
    return 0;
}