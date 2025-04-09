#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll,ll> tup;
#define endl "\n"
#define INF 1234567890123ULL
ll N, M, K;
ll a[1001][1001];
ll visited[1001][1001][11];
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

void bfs() {
	ll x, y, cy, cx, i, d, k, n;
	queue<tup> q;
	fill_n(&visited[0][0][0], 1001 * 1001 * 11, INF);
	q.push(tup(1, 1, K, 1));
	visited[1][1][K] = 1;
	while (!q.empty()) {
		tie(cy, cx, k, d) = q.front();
		q.pop();
		for (i=0;i<4;i++) {
			y = cy + dy[i];
			x = cx + dx[i];
			if (y < 1 || y > N || x < 1 || x > M)
				continue;
			if (!a[y][x]) {
				n = d + 1;
				if (visited[y][x][k] > n) {
					visited[y][x][k] = n;
					q.push(tup(y, x, k, n));
				}
			} else if (k) {
				n = (d + 2) & ~1;
				if (visited[y][x][k-1] > n) {
					visited[y][x][k-1] = n;
					q.push(tup(y, x, k-1, n));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c;
	ll i, j;
	cin >> N >> M >> K;
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	bfs();
	ll ans = INF;
	for (i=0;i<=K;i++)
		ans = min(ans, visited[N][M][i]);

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;
	return 0;
}
