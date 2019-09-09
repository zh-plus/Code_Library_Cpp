//
// Created by 10578 on 9/6/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <stdint-gcc.h>
#include <string.h>

void swap(double a[]){
    double temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}


int main(){
    int l;
    scanf("%d", &l);
    int a[l];
    for (int i = 0, sz = sizeof(a) / sizeof(a[0]); i < sz; ++i) {
        printf("%d\n", a[i]);
    }

    const char *s = "12345";
    char *s1 = "000000";
    s1[0] = '1';
//    memcpy(s1, s, strlen(s) + 1);
    printf("%s", s1);

    return 0;
}