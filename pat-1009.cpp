#include <stdio.h>

double a[1001] = {0}, b[1001]={0};
double c[2002] = {0};

int main ()
{
	int i, j;
	int n = 0;
	double in;

	scanf ("%d", &n);
	for (i = 0; i < n; i++){
		scanf ("%d%lf", &j,  &in);
		a[j] = in;
	}
	scanf ("%d", &n);
	for (i = 0; i < n; i++){
		scanf ("%d%lf", &j,  &in);
		b[j] = in;
	}
	for (i = 0; i < 1001; i++)
		for (j = 0; j < 1001; j++)
			c[i + j] += a[i] * b[j];

   n = 0;
	for (i = 0; i < 2002; i++)
		if (c[i] != 0) n++;
	printf ("%d", n);
	for (i = 2001; i >=0; i--)
		if (c[i] != 0 ) printf (" %d %.1lf", i, c[i]);	
	if (n == 0)
		printf (" 0.0 0.0");
	putchar ('\n');
	
	return 0;
}

