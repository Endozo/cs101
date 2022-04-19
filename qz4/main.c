#include<stdio.h>
#include<stdlib.h>

void swap (int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("after swap, n = %d, m = %d\n", *a, *b);
}

void swapArray(int a[], int  b[], int size) {
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = a[i];
    }
    for (int i = 0; i < size; i++) {
        a[i] = b[i];
    }
    for (int i = 0; i < size; i++) {
        b[i] = temp[i];
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == size - 1) printf("%d", a[i]);
        else printf("%d, ", a[i]);
    }
    printf("]\n");
}

char* copy_string(char* s) {
    char* str = (char*)calloc(*s, sizeof(char));

    str = s;

    return str;
}



int main() {
    int n, m;
    n = 1;
    m = 2;
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);

    printf("No.1---------------\n");
    swap(&n, &m);
    printf("No.2---------------\n");
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    printf("No.3---------------\n");
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    cp_str = NULL;

    return 0;
}