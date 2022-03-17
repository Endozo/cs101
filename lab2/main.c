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
    int sid;
    int n;
    int set;
    int lotto[5][7];
    int alotto[5][7];
    int num[5][69] = {0};
    int Max = 69;
    int min = 1;
    int sMax = 10;
    int max;
    time_t curtime;
    srand((unsigned) time(NULL));
    time(&curtime);
    lotto_record_t yourlotto;

    printf("Please enter operators number(0-5): ");
    scanf("%d", &sid);
    printf("How many set do you want to buy: ");
    scanf("%d", &set);

    for (int i = 0; i < set; i++) {
        for (int j = 0; j < 6; j++) {
            n = rand() % (Max - min + 1) + min;
            while (num[i][n - 1]) {
                n = rand() % (Max - min + 1) + min;
            }
            lotto[i][j] = n;
            num[i][n - 1] = 1;
        }
        lotto[i][6] = rand() % (sMax - min + 1) + min;
    }

    for (int i = 0; i < set; i++) {
        for (int j = 0; j < 6; j++) {
            alotto[i][j] = lotto[i][j];
            max = j;
            for (int k = 0; k < 6; k++) {
                if (lotto[i][k] > alotto[i][j]) {
                    alotto[i][j] = lotto[i][k];
                    max = k;
                }
            }
            lotto[i][max] = 0;
        }
        alotto[i][6] = lotto[i][6];
    }

    printf("Done your lotto will write into lotto[*]\n");

    FILE* file;
    char bin = '0';
    char count;

    file = fopen("counter.bin", "r+");
    if (file) {
        fseek(file, 0, SEEK_SET);
        count = fgetc(file);
        fclose(file);
    } else {
        file = fopen("counter.bin", "w+");
        fprintf(file, "%c", bin);
        count = bin;
        fclose(file);
    }

    count += 1;
    file = fopen("counter.bin", "w+");
    fprintf(file, "%c", count);
    fclose(file);

    FILE* id;
    id = fopen("operator_id.bin", "w+");
    
    fprintf(id, "user_id[0000%d]", sid);
    
    fclose(id);

    FILE* fp;

    if (count == '1') {
        fp = fopen("lotto[0001].txt","w+");
    } else if (count == '2') {
        fp = fopen("lotto[0002].txt","w+");
    } else if (count == '3') {
        fp = fopen("lotto[0003].txt","w+");
    } else if (count == '4') {
        fp = fopen("lotto[0004].txt","w+");
    } else if (count == '5') {
        fp = fopen("lotto[0005].txt","w+");
    } else {
        fp = fopen("lotto.txt", "w+");
    }

    fprintf(fp, "=========lotto649=========\n");
    fprintf(fp, "========+NO.0000%c+========\n", count);
    fprintf(fp, " %s\n", ctime(&curtime));
    for (int i = 0; i < set; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        for (int j = 0; j < 7; j++) {
            if (alotto[i][j] < 10) {
                fprintf(fp, "0");
            }
            fprintf(fp, "%d ", alotto[i][j]);
        }
        fprintf(fp, "\n");
    }
    while (set < 5) {
        set += 1;
        fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", set);
    }
    fprintf(fp, "========+OP.0000%d+========\n", sid);
    
    fclose(fp);

    yourlotto.lotto_no = count - '0';
    yourlotto.lotto_receipt = yourlotto.lotto_no * 50 * 1.1;
    yourlotto.emp_id = sid;
    strftime(yourlotto.lotto_date, 100, "%Y%m%d", localtime(&curtime));
    strftime(yourlotto.lotto_time, 100, "%H:%M:%S", localtime(&curtime));

    file = fopen("record.bin", "append(ab)");

    fprintf(file, "======================\n");
    fprintf(file, "Lotto Number: %d\n", yourlotto.lotto_no);
    fprintf(file, "Receipt Now: %d\n", yourlotto.lotto_receipt);
    fprintf(file, "User ID: %d\n", yourlotto.emp_id);
    fprintf(file, "Date today: %s\n", yourlotto.lotto_date);
    fprintf(file, "Time Now: %s\n", yourlotto.lotto_time);


    fclose(file);

    return 0;
}