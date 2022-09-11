#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll r, c;
ll m[5][5];
ll dist[5][5];
ll dx[4] = { -1, 1, 0, 0 };
ll dy[4] = { 0, 0, -1, 1 };
void bfs(ll goal) {
	ll y, x, nx, ny, i, j, maxx, maxy;
	queue<pa> q;
	q.push(pa(r, c));
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		if (m[y][x] == goal) {
			r = y;
			c = x;
			break;
		}
		for (i=0;i<4;i++) {
			nx = dx[i] + x;
			ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
			if (m[ny][nx] == -1) continue;
			maxx = nx;
			maxy = ny;
			while (maxx+dx[i] >= 0 && maxy+dy[i] >= 0 && maxx+dx[i] <= 4 && maxy+dy[i] <= 4 && m[maxy][maxx] != 7) {
				if (m[maxy+dy[i]][maxx+dx[i]] == -1) break;
				maxx += dx[i];
				maxy += dy[i];
			}
			if (!dist[ny][nx]) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push(pa(ny, nx));
			}
			if (!dist[maxy][maxx] && (maxx != nx || maxy != ny)) {
				dist[maxy][maxx] = dist[y][x] + 1;
				q.push(pa(maxy, maxx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, ans = 0;
	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			cin >> m[i][j];
		}
	}
	cin >> r >> c;
	bool ok = true;
	for (i=1;i<=6;i++) {
		memset(dist, 0, sizeof(dist));
		bfs(i);
		if (m[r][c] != i) {
			ok = false;
			break;
		}
		ans += dist[r][c];
	}
	if (ok)
		cout << ans << endl;
	else
		cout << "-1\n";

	return 0;
}
