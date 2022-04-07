#include<stdio.h>

void rec_dec(char* s) {
	while(*s) {
		printf("%c", *s);
		s++;
	}
}

void hanoi_tower(int level, char A, char B, char C) {
	FILE* fp;
	fopen(fp, "hanoi.txt", "w+");

	if (level == 1) {
		fprintf("Move disk %d from %c to %c\n",level, A, C, fp);
	} else {
		hanoi_tower(level - 1, A, C, B);
		hanoi_tower(1, A, B, C);
		hanoi_tower(level - 1, B, A, C);
	}

	fclose(fp);
}

int multiplication(int i, int j) {
	if (i == 10) {
		return 0;
	} else if (j == 9) {
		printf("%d*%d=%d \n", i, j, i * j);
		multiplication(i + 1, 1);
	} else {
		printf("%d*%d=%d ", i, j, i * j);
		multiplication(i, j + 1);
	}
}

int main() {
	char s[] = "1234567890";

	//rec_dec(s);
	printf("func#1----------------------------------\n");
	hanoi_tower(16, 'A', 'B', 'C');
	printf("func#2----------------------------------\n");
	multiplication(1, 1);
	printf("func#3----------------------------------\n");

	return 0;
}
