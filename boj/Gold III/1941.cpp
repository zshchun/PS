#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int,int> tup;
#define endl "\n"
#define INF 123456789
char a[5][5];
bool visited[5][5];
int ans, S, Y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x, int z) {
    int i, j;
    if (visited[y][x])
        return;
    visited[y][x] = 1;

    if (a[y][x] == 'S')
        S++;
    else if (a[y][x] == 'Y')
        Y++;

    for (i=0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || !(z & (1<<(ny*5+nx))))
            continue;
        dfs(ny, nx, z);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i, j, k;
    for (i=0;i<5;i++)
        for (j=0;j<5;j++)
            cin >> a[i][j];

    for (i=0;i<(1<<25);i++) {
        if (__builtin_popcount(i) != 7) continue;
        int xy = __builtin_ffs(i) - 1;
        int y = xy / 5;
        int x = xy % 5;
        S = 0; Y = 0;
        memset(visited, 0, sizeof(visited));
        dfs(y, x, i);
        if (S + Y == 7 && S > Y) ans++;
    }

    cout << ans << endl;

    return 0;
}
