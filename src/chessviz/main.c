#include "../libchessviz/chessviz.h"
#include "int_switch_char.h"
#include <stdio.h>

int check(int size, char yts, int xs, char ytf, int xf);

int main()
{
    int cor[FIELD_SIZE][FIELD_SIZE];
    char trash, yts, ytf;
    int xs, ys, xf, yf, finish = 0, turne = 0;
    printf("Input format: char int char char inr like e2-e4. \n");
    start_pos(cor);

    print(cor);
    printf("Turne White\n");
    for (int i; i < FIELD_SIZE; i++) {
        for (int j; j < FIELD_SIZE; j++) {
            printf("%d", cor[j][i]);
        }
        printf("\n");
    }
    while (finish != 1) {
        if (check(scanf("%c%d%c%c%d", &yts, &xs, &trash, &ytf, &xf),
                  yts,
                  xs,
                  ytf,
                  xf)
            == 1) {
            xs = 8 - xs;
            xf = 8 - xf;
            ys = char_int(yts);
            yf = char_int(ytf);
            if (turne == 1) {
                if (move_true_check(xs, ys, xf, yf, cor, turne) == 1)
                    turne = 0;
            } else if (turne == 0) {
                if (move_true_check(xs, ys, xf, yf, cor, turne) == 1)
                    turne = 1;
            }
            print(cor);
            if (turne == 1) {
                printf("Turne Black\n");
            } else if (turne == 0) {
                printf("Turne White\n");
            }
        } else {
            printf("Error input\n");
        }
    }
    return 0;
}

int check(int size, char yts, int xs, char ytf, int xf)
{
    int out = 0;
    if (size == 5) {
        if (xs <= 8 && xs >= 1) {
            if (xf <= 8 && xf >= 1) {
                if (yts <= 'h' && yts >= 'a') {
                    if (ytf <= 'h' && ytf >= 'a') {
                        out = 1;
                    } else {
                        out = 0;
                    }
                } else {
                    out = 0;
                }
            } else {
                out = 0;
            }
        } else {
            out = 0;
        }
    } else {
        out = 0;
    }
    return out;
}
