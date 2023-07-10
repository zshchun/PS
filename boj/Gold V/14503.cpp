#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, r, c, d, ans;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int a[51][51];
int visited[51][51];

void dfs(int y, int x, int d) {
	int i, ny, nx, nd;
	if (!visited[y][x]) {
		ans++;
	}
	visited[y][x] = 1;
	bool found = false;
	for (i=3;i>=0;i--) {
		nd = (i + d) % 4;
		ny = y + dy[nd];
		nx = x + dx[nd];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (!a[ny][nx] && !visited[ny][nx]) {
			found = true;
			dfs(ny, nx, nd);
			break;
		}
	}
	if (!found) {
		nd = (d + 2) % 4;
		ny = y + dy[nd];
		nx = x + dx[nd];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			return;
		if (a[ny][nx])
			return;
		dfs(ny, nx, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
		}
	}

	dfs(r, c, d);

	cout << ans << endl;

	return 0;
}
