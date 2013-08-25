#include <cstdio>
#include <cctype>
#include <climits>

int getd(const char& c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return c - 'a' + 10;
    }
}

long long  convert(char* n, long long radix, long long max) {
    long long r = 0;
    while (*n != 0) {
        int num = getd(*n);
        if ((LLONG_MAX - num) / radix < r) { // LLONG_MAX exceed
            return max + 1;
        }
        r = radix * r + num;
        n++;
    }
    return r;
}

int test(char* n1, long long radix, char* n2) {
    long long nn1 = convert(n1, radix, LLONG_MAX-1);
    long long left = 1, right = LLONG_MAX, now, m;
    for(int i=0; n2[i] != 0; i++) {
        int n=getd(n2[i]);
        left = left > n ? left : n;
    }
    left++;
    while (left < right) {
        m = (right - left) / 2 + left;
        now = convert(n2, m, nn1);
        if (now == nn1) {
            right = m;
        } else if (now > nn1) {
            right = m - 1;
        } else {
            left = m + 1;
        }
    }
    if (convert(n2, left, LLONG_MAX-1) != nn1)
        left = -1;
    return left;
}

int main() {
    char n1[10], n2[10];
    long long radix, r;
    int tag;
    scanf("%s %s %d %lld", n1, n2, &tag, &radix);
    if (tag == 1) {
        r = test(n1, radix, n2);
    } else {
        r = test(n2, radix, n1);
    }
    if (r == -1) {
        puts("Impossible");
    } else {
        printf("%lld", r);
    }
    return 0;
}
