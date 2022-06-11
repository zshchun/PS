#include <bits/stdc++.h>
using namespace std;
const int ds[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int a[51][51];
int M, N, K;

void bfs(int sx, int sy) {
	int i, tx, ty, x, y;
	queue<pair<int,int>> q;
	pair<int,int> p;
	q.push(make_pair(sx, sy));
	a[sx][sy] = 0;

	while (!q.empty()) {
		p = q.front();
		q.pop();
		x = p.first;
		y = p.second;
		for (i=0;i<4;i++) {
			tx = x + ds[i][0];
			ty = y + ds[i][1];
			if (tx >= 0 && tx < M && ty >= 0 && ty < N && a[tx][ty]) {
				q.push(make_pair(tx, ty));
				a[tx][ty] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, j, x, y, ans;
	cin >> t;
	while (t--) {
		cin >> M >> N >> K;
		memset(a, 0, sizeof(a));
		ans = 0;
		for (i=0;i<K;i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				if (a[j][i]) {
					bfs(j, i);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
