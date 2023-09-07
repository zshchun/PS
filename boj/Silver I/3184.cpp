#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string s[251];
bool visited[251][251];
int v, o, R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x) {
        int ny, nx;

        if (visited[y][x])
                return;
        visited[y][x] = 1;

        if (s[y][x] == 'v')
                v++;
        else if (s[y][x] == 'o')
                o++;

        for (int i=0;i<4;i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || s[ny][nx] == '#')
                        continue;
                dfs(ny, nx);
        }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        int i, j, sheep = 0, wolf = 0;
        cin >> R >> C;

        for (i=0;i<R;i++) {
                cin >> s[i];
        }

        for(i=0;i<R;i++) {
                for (j=0;j<C;j++) {
                        if (s[i][j] != '#' && !visited[i][j]) {
                                v = 0; o = 0;
                                dfs(i, j);
                                if (v >= o)
                                        wolf += v;
                                else
                                        sheep += o;
                                               
                        }
                }
        }

        cout << sheep << ' ' << wolf << endl;

	return 0;
}
