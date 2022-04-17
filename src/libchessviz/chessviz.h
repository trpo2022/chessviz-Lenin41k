#pragma once
#define FIELD_SIZE 9

enum Figure {
    KING = 10,
    QUEEN = 20,
    ROOK = 50,
    KNIGHT = 40,
    BISHOP = 30,
    PAWN = 60
};

void print(int cor[][FIELD_SIZE]);
void start_pos(int cor[][FIELD_SIZE]);
int move_true_check(
        int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE], int color);
void move(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]);
