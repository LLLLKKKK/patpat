#include <stdio.h>

double a[1001] = {0}, b[1001]={0};
double c[2002] = {0};

int main ()
{
    int n, exp;
    double coef;

    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
        scanf ("%d%lf", &exp,  &coef);
        a[exp] = coef;
    }
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
        scanf ("%d%lf", &exp,  &coef);
        b[exp] = coef;
    }
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            c[i + j] += a[i] * b[j];

    n = 0;
    for (int i = 0; i < 2002; i++)
        if (c[i] != 0) n++;
    printf ("%d", n);
    for (int i = 2001; i >=0; i--)
        if (c[i] != 0 ) printf (" %d %.1lf", i, c[i]);	
    if (n == 0)
        printf (" 0.0 0.0");
    putchar ('\n');
    
    return 0;
}

