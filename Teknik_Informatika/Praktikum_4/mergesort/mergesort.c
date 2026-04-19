#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();
    
    FILE *data_1;

    data_1 = fopen("data1.txt", "r");
    if (data_1 == NULL) return 1;

    int n;
    fscanf(data_1, "%d", &n);

    int arr1[1000];
    for(int i = 0; i<n; i++) {
        fscanf(data_1, "%d", &arr1[i]);
    }

    fclose(data_1);

    FILE *data_2;

    data_2 = fopen("data2.txt", "r");
    if (data_2 == NULL) return 1;

    int m;
    fscanf(data_2, "%d", &m);

    int arr2[1000];
    for(int i = 0; i<m; i++) {
        fscanf(data_2, "%d", &arr2[i]);
    }

    fclose(data_2);

    int i = 0, j = 0;
    int spc = 1;

    while (i < n && j < m) {
        if(!spc) printf(" ");
        if(arr1[i] <= arr2[j]) {
            printf("%d", arr1[i]);
            i++;
        } 
        else {
            printf("%d", arr2[j]);
            j++;
        }
        spc = 0;
    }

    while (i < n) {
        if (!spc) printf(" ");
        printf("%d", arr1[i]);
        i++;
        spc = 0;
    }

    while (j < m) {
        if (!spc) printf(" ");
        printf("%d", arr2[j]);
        j++;
        spc = 0;
    }

    printf("\n");

    return 0;
}