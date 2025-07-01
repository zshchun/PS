#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;
int visited[501][501];
int a[501][501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
enum { U, R, D, L, };

int dfs(int cy, int cx) {
	if (visited[cy][cx])
		return visited[cy][cx];
	visited[cy][cx] = -1;
	int d = a[cy][cx];
	int y = cy + dy[d];
	int x = cx + dx[d];

	if (y >= N || y < 0 || x < 0 || x >= M) {
		visited[cy][cx] = 1;
		return 1;
	}
	return visited[cy][cx] = dfs(y, x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0;
	char c;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			if (c == 'U') a[i][j] = U;
			else if (c == 'D') a[i][j] = D;
			else if (c == 'R') a[i][j] = R;
			else if (c == 'L') a[i][j] = L;
		}
	}

	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			if (!visited[i][j])
				dfs(i, j);
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			if (visited[i][j] > 0)
				ans++;
	cout << ans << endl;
	return 0;
}
