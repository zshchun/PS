#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int R, C;
int a[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x, int used) {
	int ret = 1;

	used |= a[y][x];
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || ny >= R || nx >= C) continue;
		if (a[ny][nx] & used) continue;
		ret = max(ret, dfs(ny, nx, used) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans;
	char c;
	cin >> R >> C;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> c;
			a[i][j] = 1 << (c - 'A');
		}
	}
	ans = dfs(0, 0, 0);

	cout << ans << endl;

	return 0;
}
