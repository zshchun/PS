#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int m, n, ans;
int a[501][501];
int dp[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x) {
	if (y == m-1 && x == n-1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0;

	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (a[y][x] <= a[ny][nx])
			continue;
		dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> m >> n;

	fill(&dp[0][0], &dp[500][500], -1);

	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			cin >> a[i][j];

	cout << dfs(0, 0) << endl;

	return 0;
}
