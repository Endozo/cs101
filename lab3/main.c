#include<stdio.h>

int my_strlen(char* s) {
    int len = 0;
    for (int i = 0; *s != 0; s++) len++;
    return len;
}

int rec_strlen(char* s) {
    if (*s == 0) return 0;
    return rec_strlen(s+1) + 1;
}

char * my_sort(char* s) {
    
}

int main() {
    char s[] = "IU is a girl!";

    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    printf("sort = %s\n", my_sort(s));

    return 0;
}