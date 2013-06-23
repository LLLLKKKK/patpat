#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct cc {
  string d;
  int n;
};
cc gao(const string& a, int n) {
  int i = 0;
  int point = a.length();
  int start = -1;
  while (i < a.length()) {
    if (a[i] != '0' && a[i] != '.' && start == -1)
      start = i;
    if (a[i] == '.')
      point = i;
    i++;
  } 
  cc c;
  //printf("%d %d\n", start, point);
  if (start == -1) {
    c.d.append(n, '0');
    c.n = 0;
    return c;
  }
  if (start < point) {
    c.n = point - start;
    c.d += a.substr(start, point - start);
  } else {
    c.n = point - start + 1;
  }
  if (point < a.length() - 1) {
    if (start < point)
      c.d += a.substr(point + 1);
    else
      c.d += a.substr(start);
  }
  if (n > c.d.length())
    c.d.append(n - c.d.length(), '0');
  else
    c.d = c.d.substr(0, n);
  //cout << c.d << ' ' << c.n << endl;
  return c;
}
void printcc(const cc& c) {
  printf("0.%s*10^%d", c.d.c_str(), c.n);
}

int main() {
  string a, b;
  int n;
  cin >> n >> a >> b;
  if (n==0) {
    puts("YES 0"); return 0;
  }
  auto aa = gao(a, n);
  auto bb = gao(b, n);
  if (aa.d == bb.d && bb.n == aa.n) {
    printf("YES ");
    printcc(aa); puts("");
  } else {
    printf("NO ");
    printcc(aa); putchar(' '); printcc(bb); puts("");
  }
  return 0;
}
