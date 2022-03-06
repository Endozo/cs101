#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int set;
    int lotto[5][6];
    int alotto[5][6];
    int min = 1;
    int Max = 69;
    int sMax = 10;
    int max;
    time_t curtime;
    srand((unsigned) time(NULL));

    time(&curtime);

    printf("Welcome CGU lotto!\n");
    printf("Please tell me how many set do you want to buy: ");
    scanf("%d", &set);

    for (int i = 0; i < set; i++) {
        for (int j = 0; j < 5; j++) {
            lotto[i][j] = rand() % (Max - min + 1) - min;
        }
        lotto[i][5] = rand() % (sMax - min + 1) - min;
    }

    for (int i = 0; i < set; i++) {
        for (int j = 0; j < 5; j++) {
            alotto[i][j] = lotto [i][j];
            max = j;
            for (int k = 0; k < 5; k++) {
                if (lotto[i][k] > alotto[i][j]) {
                    alotto[i][j] = lotto[i][k];
                    max = k;
                }
            }
            lotto[i][max] = 0;
        }
        alotto[i][5] = lotto[i][5];
    }

    printf("Done your lotto number will put into the file lotto.txt.\n");

    FILE* fp;
    
    fp = fopen("lotto.txt", "w+");
    fprintf(fp, "========lotto649========\n");
    fprintf(fp, "%s\n", ctime(&curtime));
    for (int i = 0; i < set; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        for (int j = 0; j < 6; j++) {
            fprintf(fp, "%d ", alotto[i][j]);
        }
        fprintf(fp, "\n");
    }
    while (set < 5) {
        set += 1;
        fprintf(fp, "[%d]: -- -- -- -- -- -\n", set);
    }
    
    fclose(fp);

    return 0;
}