#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, K, cnt, ans;
ll a[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x) {
	if (visited[y][x] || !a[y][x])
		return;
	visited[y][x] = 1;
	cnt++;
	int nx, ny;
	for (int i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || ny > N || nx > M)
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, y, x;
	cin >> N >> M >> K;
	for (i=0;i<K;i++) {
		cin >> y >> x;
		a[y][x] = 1;
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cnt = 0;
			if (!visited[i][j] && a[i][j])
				dfs(i, j);
			if (cnt > ans)
				ans = cnt;
		}
	}
	cout << ans << endl;
	return 0;
}
