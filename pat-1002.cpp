#include <cstdio>

double a[1001] = {0};
double b[1001] = {0};

void readp(double *p) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    double b;
    scanf("%d %lf", &a, &b);
    p[a] = b;
  }
}
int main() {
  readp(a);
  readp(b);
  int n = 0;
  for (int i = 0; i < 1001; i++) {
    a[i] += b[i];
    if (a[i] != 0) {
      n++;
    }
  }
  printf("%d", n);
  for (int i = 1000; i >= 0; i--) {
    if (a[i] != 0) {
      printf(" %d %.1lf", i, a[i]);
    }
  }
  putchar('\n');
  return 0;
}
