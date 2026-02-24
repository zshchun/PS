#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
int N, M, ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[51][51];
bool used[51][51];
int dp[51][51];

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M || !a[y][x])
		return 0;
	int ret = 1;
	if (used[y][x]) {
		cout << "-1\n";
		exit(0);
	}
	if (dp[y][x] > 0) return dp[y][x];

	used[y][x] = 1;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i] * a[y][x];
		int nx = x + dx[i] * a[y][x];
		ret = max(ret, dfs(ny, nx) + 1);
	}
	used[y][x] = 0;
	return dp[y][x] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			if (c != 'H')
				a[i][j] = c - '0';
		}
	}
	ans = dfs(0, 0);
	cout << ans << endl;
	return 0;
}
