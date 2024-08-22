#include <math.h>
#include <stdio.h>
#include "basic_func.h"

const double proximity_pozitive_null = 0.0000001;
int is_zero(double x)
{
    return  fabs(x) < proximity_pozitive_null;
}

void clean_reading_boofer(void)
{
    int clean = getchar();
    while (clean != '\n')
    {
        clean = getchar();
        if (clean == EOF) return;
    }
}

