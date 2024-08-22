# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include "my_assert.h"
# include <math.h>
# include "testing_program.h"
# include "solver_func.h"
# include "basic_func.h"
# include "colorful_print.h"


bool reading_cooficients_from_terminal(double* a, double* b, double* c);



int main(int argc, char **argv)
{


    if (argc >= 2)
    {
        if (strcmp(argv[1], "-t") == 0)
        {

            FILE *fp;
            fp = fopen("../../data.txt","r");
            reading_coeficients_from_file_to_struct(fp);
            assert(check_solver_by_tests());
            printf("All Tests are correctly!\n");
        }
        else
        {
            printf("Unsupportable command! Exit.");
            return 1;
        }

    }
    printf("Write down coefficients in format a b c:\n");



    double a = 0, b = 0, c = 0;

    bool flag = reading_cooficients_from_terminal(&a, &b, &c);

    if (flag) return 1;

    double x1 = 0, x2 = 0;
    int n_roots = solve_square_func(a, b, c, &x1, &x2);

    switch (n_roots)
    {
        case 0: change_consol_color(COLOR_RED);
                printf("There is no roots!");
                break;
        case 1: change_consol_color(COLOR_GREEN);
                printf("There is one root: %lg.", x1);
                break;
        case 2: change_consol_color(COLOR_BLUE);
                printf("There are two roots: %lg, %lg.", x1, x2);
                break;
        case inf_roots: change_consol_color(COLOR_PURPLE);
                        printf("There are infinity roots!");
                        break;
        default:    change_consol_color(COLOR_ORANGE);
                    printf("Error: nRoots = %d", n_roots);
    }

    change_consol_color(COLOR_WHITE);

    return 0;
}





bool reading_cooficients_from_terminal(double* a, double* b, double* c)
{

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("Wrong input! Try again!\n");
        printf("Write down coeficients in format a b c:\n");

        int clean = getchar();
        while (clean != '\n')
        {
            clean = getchar();
            if (clean == EOF) return true;
        }
    }

    return false;
}



