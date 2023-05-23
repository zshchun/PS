#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int m[101][101];
int visited[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int T, H, W, ans;

void dfs(int y, int x) {
	int i;
	visited[y][x] = 1;
	for (i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		if (!visited[ny][nx] && m[ny][nx] == 1)
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	int i, j;
	char c;
	while (T--) {
		cin >> H >> W;
		ans = 0;
		memset(visited, 0, sizeof(visited));
		for (i=0;i<H;i++) {
			for (j=0;j<W;j++) {
				cin >> c;
				if (c == '#')
					m[i][j] = 1;
				else
					m[i][j] = 0;
			}
		}
		for (i=0;i<H;i++) {
			for (j=0;j<W;j++) {
				if (m[i][j] && !visited[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
