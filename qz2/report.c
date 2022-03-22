#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct lotto {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[100];
    char lotto_time[100];
} lotto_record_t;

int main() {
    lotto_record_t buffer;
    lotto_record_t alotto[100];
    int i = 0;
    int n = 0;
    int k = 0;
    int number;
    int set;
    char date[100] = "0";
    int receipt;
    int index;
    int fno;
    int fset;
    int frec;
    char curdate[100];
    time_t curtime;
    time(&curtime);
    strftime(curdate, 100, "%Y%m%d", localtime(&curtime));
    FILE* fp;
    FILE* file;
    fp = fopen("record.bin", "r");
    file = fopen("record.txt", "w+");

    fprintf(file, "========= lotto649 Report =========\n");
    fprintf(file, "- Date ------ Num. ------ Receipt -\n");
    
    while(fread(&buffer, sizeof(lotto_record_t), 1, fp) != NULL) {
        index = sizeof(buffer.lotto_date) / sizeof(char);
        alotto[i] = buffer;
        if (buffer.lotto_date[index] != date[index]) {
            for (int x = i - 1; x >= k; x--) {
                receipt += alotto[x].lotto_receipt;
                number += alotto[x].lotto_no;
            }
            set = receipt / 55;
            n++;
            if (date[0] != '0') {
                fprintf(file, "%s      ", date);
                fprintf(file, "%d/%d           ", number, set);                                                  
                fprintf(file, "%d\n", receipt);
            }
            for (int j = 0; j < index; j++) {
                date[j] = alotto[i].lotto_date[j];
            }
            k = i;
        }
        frec += receipt;
        fno += number;
        fset += set;
        receipt = 0;
        set = 0;
        number = 0;
        i++;
    }
    
    for (int x = i - 1; x >= k; x--) {
        receipt += alotto[x].lotto_receipt;
        number += alotto[x].lotto_no;
    }

    set = receipt / 55;

    if (date[0] != '0') {
        fprintf(file, "%s      ", date);
        fprintf(file, "%d/%d           ", number, set);                                                  
        fprintf(file, "%d\n", receipt);
    }

    for (int j = 0; j < index; j++) {
        date[j] = alotto[i].lotto_date[j];
    }

    k = i;
    frec += receipt;
    fno += number;
    fset += set;

    fprintf(file, "-----------------------------------\n");
    fprintf(file, "       %d      %d/%d           %d\n", n, fno, fset, frec);
    fprintf(file, "======== %s Printed =========\n", curdate);

    fclose(fp);
    fclose(file);
    
    return 0;
}