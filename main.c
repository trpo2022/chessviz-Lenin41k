#include <stdio.h>

int charint(char);
char intchar(int);
void print(int*);
void startpos(int*);

int main() {
	int cor[8][8]; 
	startpos(&cor);
	print(&cor)
}

void startpos(int* cor) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0 || j == 1) {
				if (j == 1)
					cor[i][j] = 61;
				if (j == 0) {
					if (i == 0 || i == 7)
						cor[i][j] == 51;
					if (i == 1 || i == 6)
						cor[i][j] == 41;
					if (i == 2 || i == 5)
						cor[i][j] == 31;
					if (i == 3)
						cor[i][j] == 21;
					if (i == 4)
						cor[i][j] == 11;
				}
			}
			if (j == 7 || j == 6) {
				if (j == 6)
					cor[i][j] = 60;
				if (j == 0) {
					if (i == 0 || i == 7)
						cor[i][j] == 50;
					if (i == 1 || i == 6)
						cor[i][j] == 40;
					if (i == 2 || i == 5)
						cor[i][j] == 30;
					if (i == 3)
						cor[i][j] == 20;
					if (i == 4)
						cor[i][j] == 10;
				}
			}
		}
	}
}

void print(int* cor) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (cor[i][j] == 10)
				printf("K");
			if (cor[i][j] == 11)
				printf("k");
			if (cor[i][j] == 20)
				printf("Q");
			if (cor[i][j] == 21)
				printf("q");
			if (cor[i][j] == 30)
				printf("R");
			if (cor[i][j] == 31)
				printf("r");
			if (cor[i][j] == 40)
				printf("N");
			if (cor[i][j] == 41)
				printf("n");
			if (cor[i][j] == 50)
				printf("B");
			if (cor[i][j] == 51)
				printf("b");
			if (cor[i][j] == 60)
				printf("P");
			if (cor[i][j] == 61)
				printf("p");
			if (cor[i][j] == 0 && j != 8 && i != 0)
				printf(" ");
			if (i == 0 && j != 8)
				printf("%d", j); 
			if (j == 8 && i != 0)
				printf("%c", intchar(i))
		}
		printf("\n");
	}	
}

int charint(char n) {
	int m;
	if (n == 'a')
		m = 1; 
	if (n == 'b')
		m = 2;
	if (n == 'c')
		m = 3;
	if (n == 'd')
		m = 4;
	if (n == 'e')
		m = 5;
	if (n == 'f')
		m = 6;
	if (n == 'g')
		m = 7;
	if (n == 'h')
		m = 8;
	return m;
}


char intchar(int n) {
	char m;
	if (n == 1)
		m = 'a';
	if (n == 2)
		m = 'b';
	if (n == 3)
		m = 'c';
	if (n == 4)
		m = 'd';
	if (n == 5)
		m = 'e';
	if (n == 6)
		m = 'f';
	if (n == 7)
		m = 'g';
	if (n == 8)
		m = 'h';
	return m; 
}