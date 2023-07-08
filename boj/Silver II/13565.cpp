#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[1001][1001];
bool visited[1001][1001];
ll M, N;

ll dy[4] = { 0, 0, 1, -1 };
ll dx[4] = { 1, -1, 0, 0 };

void dfs(int y, int x) {
	ll nx, ny, i;
	if (visited[y][x])
		return;
	visited[y][x] = 1;
	for (i=0;i<4;i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N || a[ny][nx])
			continue;
		dfs(ny, nx);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bool ans = false;
	ll i, j;
	char ch;

	cin >> M >> N;
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			cin >> ch;
			if (ch == '1')
				a[i][j] = 1;
		}
	}

	for (j=0;j<N;j++) {
		dfs(0, j);
	}

	for (j=0;j<N;j++) {
		if (visited[M-1][j])
			ans = true;
	}

	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
