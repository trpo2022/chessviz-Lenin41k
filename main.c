#include <stdio.h>
#define FIELD_SIZE 9

int char_int(char n);
char int_char(int n);
void print(int cor[][FIELD_SIZE]);
void start_pos(int cor[][FIELD_SIZE]);
int move_true_check_black(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]);
int move_true_check_white(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]);
void move(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]);

int main() {
  int cor[FIELD_SIZE][FIELD_SIZE];
  char trash, yts, ytf;
  int xs, ys, xf, yf, finish = 0, turne = 0, check;
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
    check = scanf("%c%d%c%c%d", &yts, &xs, &trash, &ytf, &xf);
    if (check == 5) {
      if (xs <= 8 && xs >= 1)
        if (xf <= 8 && xf >= 1)
          if (yts <= 'h' && yts >= 'a')
            if (ytf <= 'h' && ytf >= 'a') {
              xs = 8 - xs;
              xf = 8 - xf;
              ys = char_int(yts);
              yf = char_int(ytf);
              if (turne == 1) {
                if (move_true_check_black(xs, ys, xf, yf, cor) == 1)
                  turne = 0;
              } else if (turne == 0) {
                if (move_true_check_white(xs, ys, xf, yf, cor) == 1)
                  turne = 1;
              }
              print(cor);
              if (turne == 1) {
                printf("Turne Black\n");
              } else if (turne == 0) {
                printf("Turne White\n");
              }
            }
    } else if (check != 5) {
      printf("Error input\n");
    }
  }
  return 0;
}

void start_pos(int cor[][FIELD_SIZE]) {
  for (int i = 0; i < FIELD_SIZE; i++) {
    for (int j = 0; j < FIELD_SIZE; j++) {
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
      } else if (j == 7 || j == 6) {
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
      } else {
        cor[i][j] = 0;
      }
    }
  }
}

void print(int cor[][FIELD_SIZE]) {
  for (int i = 0; i < FIELD_SIZE; i++) {
    for (int j = 0; j < FIELD_SIZE; j++) {
      if (j == 0 && i != 8)
        printf("%d", 8 - i);
      else if (i == 8 && j != 0)
        printf("%c", int_char(j));
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

int char_int(char n) {
  int m;
  if (n == 'a')
    m = 1;
  else if (n == 'b')
    m = 2;
  else if (n == 'c')
    m = 3;
  else if (n == 'd')
    m = 4;
  else if (n == 'e')
    m = 5;
  else if (n == 'f')
    m = 6;
  else if (n == 'g')
    m = 7;
  else if (n == 'h')
    m = 8;
  return m;
}

char int_char(int n) {
  char m;
  if (n == 1)
    m = 'a';
  else if (n == 2)
    m = 'b';
  else if (n == 3)
    m = 'c';
  else if (n == 4)
    m = 'd';
  else if (n == 5)
    m = 'e';
  else if (n == 6)
    m = 'f';
  else if (n == 7)
    m = 'g';
  else if (n == 8)
    m = 'h';
  return m;
}

int move_true_check_white(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]) {
  int true = 0, mx, my;
  if (cor[ys][xs] == 60) {
    if (xs == xf + 1 && ys == yf) {
      true = 1;
    } else if (xs == xf + 2 && xs == 6 && ys == yf) {
      true = 1;
    } else if (xs == xf + 1 && (ys == yf - 1 || ys == yf + 1) &&
               (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
      true = 1;
    }
  } else if (cor[ys][xs] == 50) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
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
  } else if (cor[ys][xs] == 40) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
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
  } else if (cor[ys][xs] == 30) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
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
  } else if (cor[ys][xs] == 20) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
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

  } else if (cor[ys][xs] == 10) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 21 && cor[yf][xf] % 2 == 1)) {
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

int move_true_check_black(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]) {
  int true = 0, mx, my;
  if (cor[ys][xs] == 61) {
    if (xs == xf - 1 && ys == yf)
      true = 1;
    else if (xs == xf - 2 && xs == 1 && ys == yf) {
      true = 1;
    } else if (xs == xf - 1 && (ys == yf - 1 || ys == yf + 1) &&
               (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
      true = 1;
    }
  } else if (cor[ys][xs] == 51) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
      if (ys == yf) {
        if (xs > xf)
          for (int i = xs; i > xf; i--) {
            if (cor[ys][i] == 0) {
              true = 1;
            } else {
              true = 0;
              break;
            }
          }
        else if (xs < xf)
          for (int i = xs; i < xf; i++) {
            if (cor[ys][i] == 0) {
              true = 1;
            } else {
              true = 0;
              break;
            }
          }
        if (xs == xf) {
          if (ys > yf)
            for (int i = ys; i > yf; i--) {
              if (cor[i][xs] == 0) {
                true = 1;
              } else {
                true = 0;
                break;
              }
            }
          else if (ys < yf)
            for (int i = ys; i < yf; i++) {
              if (cor[i][xs] == 0) {
                true = 1;
              } else {
                true = 0;
                break;
              }
            }
        }
      }
    }
  } else if (cor[ys][xs] == 41) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
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
  } else if (cor[ys][xs] == 31) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
      if (xs > xf) {
        mx = xs - 1;
        if (ys > yf) {
          my = ys - 1;
          while (mx != xf && my != yf) {
            mx--;
            my--;
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
              true = 1;
            else {
              true = 0;
              break;
            }
          }
        }
      }
    }
  } else if (cor[ys][xs] == 21) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
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
            if (cor[my][mx] == 0 || (cor[my][mx] >= 20 && cor[my][mx] % 2 == 0))
              true = 1;
            else {
              true = 0;
              break;
            }
          }
        }
      }

      if (ys == yf) {
        if (xs > xf) {
          for (int i = xs - 1; i > xf; i--) {
            if (cor[ys][i] == 0) {
              true = 1;
            } else {
              true = 0;
              break;
            }
          }
        } else if (xs < xf) {
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
    }

  } else if (cor[ys][xs] == 11) {
    if (cor[yf][xf] == 0 || (cor[yf][xf] >= 20 && cor[yf][xf] % 2 == 0)) {
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

void move(int xs, int ys, int xf, int yf, int cor[][FIELD_SIZE]) {
  cor[yf][xf] = cor[ys][xs];
  cor[ys][xs] = 0;
}
