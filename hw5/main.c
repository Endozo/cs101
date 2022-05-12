#include<stdio.h>

typedef struct my_mm {
    int nm[10];
    int* nm_p[10];
    int count;
    
} my_mm_t;

int g_mem[10];
my_mm_t mms;

void mm_status() {
    for (int i = 0; i < 10; i++) {
        if (g_mem[i] == 0) mms.nm[i] = 0;
        else mms.nm[i] = 1;
        printf("%d", mms.nm[i]);
    }
}

int* my_calloc(int n, int size) {
    mms.count++;
    int np = 0;
    for (int i = 0; i < 10; i++) {
        if (g_mem[i] == 0) np++;
        else np = 0;
        if (np >= n * size) {
            for (int j = i-np+1; j < i+1; j++)
                g_mem[j] = mms.count;
            mm_status();
            printf("\n");
            return &g_mem[i];
        }
    }
}

int* find_address(int* n, int num) {
    int count = 0;
    while(*n != num) {
        n++;
        count++;
        if (count > 10) return 0;
    }
    return n;
}

void my_free(int* p) {
    int count = 0;
    while(find_address(g_mem, *p) && count < 10) {
        int* n = find_address(g_mem, *p);
        *n = 0;
        count++;
    }
    mm_status();
    printf("\n");
}

int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);

    my_free(np1);
    my_free(np4);

    int* np5 = my_calloc(1, 3);

    return 0;
}