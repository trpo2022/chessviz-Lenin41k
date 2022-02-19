#include <stdio.h>

int charint(char);
char intchar(int);
void print(int (*)[9]);
void startpos(int(*)[9]);

int main() {
	int cor[9][9]; 
	startpos(cor);
	print(cor);
}

void startpos(int cor[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == 0 || j == 1) {
				if (j == 1)
					cor[i][j] = 61;
				if (j == 0) {
					if (i == 1 || i == 8)
						cor[i][j] = 51;
					if (i == 2 || i == 7)
						cor[i][j] = 41;
					if (i == 3 || i == 6)
						cor[i][j] = 31;
					if (i == 4)
						cor[i][j] = 21;
					if (i == 5)
						cor[i][j] = 11;
				}
			}
			if (j == 7 || j == 6) {
				if (j == 6)
					cor[i][j] = 60;
				if (j == 7) {
					if (i == 1 || i == 8)
						cor[i][j] = 50;
					if (i == 2 || i == 7)
						cor[i][j] = 40;
					if (i == 3 || i == 6)
						cor[i][j] = 30;
					if (i == 4)
						cor[i][j] = 20;
					if (i == 5)
						cor[i][j] = 10;
				}
			}
		}
	}
}

void print(int cor[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == 0 && i != 8)
				printf("%d", 8 - i);
			else if (i == 8 && j != 0)
				printf("%c", intchar(j));
			else if (cor[j][i] == 10)
				printf("K");
			else if (cor[j][i] == 11)
				printf("k");
			else if (cor[j][i] == 20)
				printf("Q");
			else if (cor[j][i] == 21)
				printf("q");
			else if (cor[j][i] == 30)
				printf("B");
			else if (cor[j][i] == 31)
				printf("b");
			else if (cor[j][i] == 40)
				printf("N");
			else if (cor[j][i] == 41)
				printf("n");
			else if (cor[j][i] == 50)
				printf("R");
			else if (cor[j][i] == 51)
				printf("r");
			else if (cor[j][i] == 60)
				printf("P");
			else if (cor[j][i] == 61)
				printf("p");
			else
				printf(" ");
			printf(" ");
		}
		printf("\n");
	}	
}
//P-60 p-61 
//R-50 r-51 
//N-40 n-41 
//B-30 b-31 
//Q-20 q-21 
//K-10 k-11
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

int movetruechek(int xs, int ys, int xf, int yf) { 

}