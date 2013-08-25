#include <cstdio>
#include <cstring>
int map[1000][1000] = {0};
int n;
void dfs(int s) {
    map[0][s] = 1;
    for (int i=1;i<=n;i++) {
        if (map[s][i] != 0 && map[0][i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m,k;
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        int a, b;
        scanf("%d%d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
    }
    while(k--) {
        int city, count=0;
        scanf("%d",&city);
        map[0][city]=-1;
        for (int i=1;i<=n;i++) {
            if (map[0][i] == 0 && i != city) {
                count++;
                dfs(i);
            }
        }
        memset(map[0], 0, sizeof(int) * 1000);
        printf("%d\n", count-1);
    }
    return 0;
}

