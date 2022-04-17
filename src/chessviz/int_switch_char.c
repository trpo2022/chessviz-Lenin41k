#include "int_switch_char.h"
#include <stdio.h>

int char_int(char n)
{
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

char int_char(int n)
{
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
