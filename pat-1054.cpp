#include <cstdio>
int color[256*256*256]={0};
int main()
{
  int m, n; scanf("%d %d", &m, &n);
  int max=0;
  for(int i=0;i<m*n;i++) {
    int c; scanf("%d", &c); color[c]++;
    if(color[c]>color[max]) max = c;
  }
  printf("%d\n", max);
  return 0;
}
