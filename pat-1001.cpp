#include <cstdio>

void pf(int n) {
  if (n < 1000) {
    printf("%d", n);
    return;
  }
  int re = n % 1000;
  int div = n / 1000;
  if (div != 0) {
    pf(div);
    putchar(',');
  }
  if (re > 100) {
    printf("%d", re);
  }
  else if (re > 10) {
    printf("0%d", re);
  }
  else {
    printf("00%d", re);
  }
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int c = a + b;
  if (c < 0) {
    c = -c;
    putchar('-');
  }
  pf(c);
  putchar('\n');
  return 0;
}
