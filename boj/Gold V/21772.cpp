#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int R, C, T, sx, sy, ans;
#define NONE   0
#define SPOTATO 1
#define WALL   2

int a[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x, int g, int n) {
	if (n == T) {
		ans = max(g, ans);
		return;
	}
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == WALL) continue;
		if (a[ny][nx] == SPOTATO) {
			a[ny][nx] = NONE;
			dfs(ny, nx, g + 1, n+1);
			a[ny][nx] = SPOTATO;
		} else {
			dfs(ny, nx, g, n+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> R >> C >> T;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> c;
			if (c == 'S') {
				a[i][j] = SPOTATO;
			} else if (c == 'G') {
				sy = i;
				sx = j;
			} else if (c == '#') {
				a[i][j] = WALL;
			}
		}
	}
	dfs(sy, sx, 0, 0);
	cout << ans << endl;
	return 0;
}
