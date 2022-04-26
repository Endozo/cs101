#include<stdio.h>
#include<stdlib.h>

typedef struct array_list {
    int number;
    int* (*func1_ptr)(int);
    void (*func2_ptr)(int*, int);
    void (*func3_ptr)(int, int*, int);
} array_list_t;

int* get_int_array(int n) {
    int* a = (int*)calloc(n, sizeof(int));
    return a;
    free(a);
}

void set_value(int* p, int v) {
    *p = v;
}

void print_array(int NO, int* p, int n) {
    printf("--------------------------------NO.%d\n[", NO);
    for (int i = 0; i < n; i++) {
        if (i == n-1) printf("%d]\n", *p);
        else printf("%d, ", *p++);
    }
}

int main() {
    array_list_t no2;
    no2.number = 20;
    no2.func1_ptr = get_int_array;
    no2.func2_ptr = set_value;
    no2.func3_ptr = print_array;
    int n = 10;
    int* ip = get_int_array(n);
    int* ip2 = no2.func1_ptr(no2.number);
    

    for (int i = 0; i < n; i++) {
        set_value(ip+i, i+1);
    }
    for (int i = 0; i < no2.number; i++) {
        no2.func2_ptr(ip2+i, i+1);
    }
    print_array(1, ip, n);
    no2.func3_ptr(2, ip2, no2.number);

    return 0;
}