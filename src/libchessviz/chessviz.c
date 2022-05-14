#include "chessviz.h"
#include "../chessviz/int_switch_char.h"
#include <stdio.h>

void start_pos(int cor[][FIELD_SIZE])
{
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (j == 0 || j == 1) {
                if (j == 1)
                    cor[i][j] = PAWN + 1;
                if (j == 0) {
                    if (i == 1 || i == 8)
                        cor[i][j] = ROOK + 1;
                    if (i == 2 || i == 7)
                        cor[i][j] = KNIGHT + 1;
                    if (i == 3 || i == 6)
                        cor[i][j] = BISHOP + 1;
                    if (i == 4)
                        cor[i][j] = QUEEN + 1;
                    if (i == 5)
                        cor[i][j] = KING + 1;
                }
            } else if (j == 7 || j == 6) {
                if (j == 6)
                    cor[i][j] = PAWN;
                if (j == 7) {
                    if (i == 1 || i == 8)
                        cor[i][j] = ROOK;
                    if (i == 2 || i == 7)
                        cor[i][j] = KNIGHT;
                    if (i == 3 || i == 6)
                        cor[i][j] = BISHOP;
                    if (i == 4)
                        cor[i][j] = QUEEN;
                    if (i == 5)
                        cor[i][j] = KING;
                }
            } else {
                cor[i][j] = 0;
            }
        }
    }
}

void print(int cor[][FIELD_SIZE])
{
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (j == 0 && i != 8)
                printf("%d", 8 - i);
            else if (i == 8 && j != 0)
                printf("%c", int_char(j));
            else if (cor[j][i] == KING)
                printf("K");
            else if (cor[j][i] == KING + 1)
                printf("k");
            else if (cor[j][i] == QUEEN)
                printf("Q");
            else if (cor[j][i] == QUEEN + 1)
                printf("q");
            else if (cor[j][i] == BISHOP)
                printf("B");
            else if (cor[j][i] == BISHOP + 1)
                printf("b");
            else if (cor[j][i] == KNIGHT)
                printf("N");
            else if (cor[j][i] == KNIGHT + 1)
                printf("n");
            else if (cor[j][i] == ROOK)
                printf("R");
            else if (cor[j][i] == ROOK + 1)
                printf("r");
            else if (cor[j][i] == PAWN)
                printf("P");
            else if (cor[j][i] == PAWN + 1)
                printf("p");
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
    }
}

int move_true_check(
        int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE], int color)
{
    int true = 0, mx, my, eat;
    if (color == 0) {
        eat = 1;
    } else if (color == 1) {
        eat = 0;
    }
    if (cor[ys][xs] == PAWN + color) {
        if (cor[ys][xs] == PAWN) {
            if (xs == xf + 1 && ys == yf && cor[yf][xf] == 0) {
                true = 1;
            } else if (
                    xs == xf + 2 && xs == 6 && ys == yf && cor[yf][xf] == 0) {
                true = 1;
            } else if (
                    xs == xf + 1 && (ys == yf - 1 || ys == yf + 1)
                    && (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
                true = 1;
            }
        }
        if (cor[ys][xs] == PAWN + 1) {
            if (xs == xf - 1 && ys == yf && cor[yf][xf] == 0) {
                true = 1;
            } else if (
                    xs == xf - 2 && xs == 1 && ys == yf && cor[yf][xf] == 0) {
                true = 1;
            } else if (
                    xs == xf - 1 && (ys == yf - 1 || ys == yf + 1)
                    && (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
                true = 1;
            }
        }
    } else if (cor[ys][xs] == ROOK + color) {
        if (cor[yf][xf] == 0
            || (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
            if (ys == yf) {
                if (xs > xf)
                    for (int i = xs - 1; i > xf; i--) {
                        if (cor[ys][i] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
            } else if (xs < xf)
                for (int i = xs + 1; i < xf; i++) {
                    if (cor[ys][i] == 0) {
                        true = 1;
                    } else {
                        true = 0;
                        break;
                    }
                }
            if (xs == xf) {
                if (ys > yf)
                    for (int i = ys - 1; i > yf; i--) {
                        if (cor[i][xs] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
                else if (ys < yf)
                    for (int i = ys + 1; i < yf; i++) {
                        if (cor[i][xs] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
            }
        }
    } else if (cor[ys][xs] == KNIGHT + color) {
        if (cor[yf][xf] == 0
            || (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
            if (xs == xf - 2) {
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
                else
                    true = 0;
            } else if (xs == xf + 2) {
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
                else
                    true = 0;
            } else if (ys == yf - 2) {
                if (xs == xf - 1 || xs == xf + 1)
                    true = 1;
                else
                    true = 0;
            } else if (ys == yf + 2) {
                if (xs == xf - 1 || xs == xf + 1)
                    true = 1;
                else
                    true = 0;
            }
        }
    } else if (cor[ys][xs] == BISHOP + color) {
        if (cor[yf][xf] == 0
            || (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
            if (xs > xf) {
                mx = xs - 1;
                if (ys > yf) {
                    my = ys - 1;
                    while (mx != xf && my != yf) {
                        mx--;
                        my--;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
                if (ys < yf) {
                    my = ys + 1;
                    while (mx != xf && my != yf) {
                        mx--;
                        my++;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
            }
            if (xs < xf) {
                mx = xs + 1;
                if (ys > yf) {
                    my = ys - 1;
                    while (mx != xf && my != yf) {
                        mx++;
                        my--;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
                if (ys < yf) {
                    my = ys + 1;
                    while (mx != xf && my != yf) {
                        mx++;
                        my++;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
            }
        }
    } else if (cor[ys][xs] == QUEEN + color) {
        if (cor[yf][xf] == 0
            || (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
            if (xs == xf) {
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
            } else if (ys == yf) {
                if (xs == xf - 1 || xs == xf + 1)
                    true = 1;
            } else if (xs == xf + 1 || xs == xf - 1) {
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
                else
                    true = 0;
            }

            if (xs > xf) {
                mx = xs - 1;
                if (ys > yf) {
                    my = ys - 1;
                    while (mx != xf && my != yf) {
                        mx--;
                        my--;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
                if (ys < yf) {
                    my = ys + 1;
                    while (mx != xf && my != yf) {
                        mx--;
                        my++;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
            }
            if (xs < xf) {
                mx = xs + 1;
                if (ys > yf) {
                    my = ys - 1;
                    while (mx != xf && my != yf) {
                        mx++;
                        my--;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
                if (ys < yf) {
                    my = ys + 1;
                    while (mx != xf && my != yf) {
                        mx++;
                        my++;
                        if (cor[my][mx] == 0)
                            true = 1;
                        else {
                            true = 0;
                            break;
                        }
                    }
                }
            }

            if (ys == yf) {
                if (xs > xf)
                    for (int i = xs - 1; i > xf; i--) {
                        if (cor[ys][i] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
                else if (xs < xf)
                    for (int i = xs + 1; i < xf; i++) {
                        if (cor[ys][i] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
            }
            if (xs == xf) {
                if (ys > yf)
                    for (int i = ys - 1; i > yf; i--) {
                        if (cor[i][xs] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
                else if (ys < yf)
                    for (int i = ys + 1; i < yf; i++) {
                        if (cor[i][xs] == 0) {
                            true = 1;
                        } else {
                            true = 0;
                            break;
                        }
                    }
            }
        }

    } else if (cor[ys][xs] == KING + color) {
        if (cor[yf][xf] == 0
            || (cor[yf][xf] >= 20 + eat && cor[yf][xf] % 2 == eat)) {
            if (xs == xf)
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
            if (ys == yf)
                if (xs == xf - 1 || xs == xf + 1)
                    true = 1;
            if (xs == xf + 1 || xs == xf - 1)
                if (ys == yf - 1 || ys == yf + 1)
                    true = 1;
        } else
            true = 0;
    }
    if (true == 1) {
        move(xs, ys, xf, yf, cor);
    } else {
        printf("Wrong coordinates, try again.\n");
    }
    return true;
}

void move(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE])
{
    cor[yf][xf] = cor[ys][xs];
    cor[ys][xs] = 0;
}
