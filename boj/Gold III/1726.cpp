#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int m, n;
int sy, sx, sd, ey, ex, ed;
int a[101][101];
int v[101][101][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	queue<tup> q;
	q.push(tup(sy, sx, sd));
	fill_n(v[0][0], 101*101*4, INF);
	int y, x, d, nd, ny, nx, i;
	v[sy][sx][sd] = 0;
	while (!q.empty()) {
		tie(y, x, d) = q.front();
		q.pop();
		if (y == ey && x == ex && d == ed)
			break;
		for (i=1;i<=3;i++) {
			ny = y + dy[d] * i;
			nx = x + dx[d] * i;
			if (ny < 0 || ny >= m || nx < 0 || nx >= n || a[ny][nx]) break;
			if (v[ny][nx][d] > v[y][x][d] + 1) {
				v[ny][nx][d] = v[y][x][d] + 1;
				q.push(tup(ny, nx, d));
			}
		}
		nd = (d + 2) % 4;
		if (v[y][x][nd] > v[y][x][d] + 1) {
			v[y][x][nd] = v[y][x][d] + 1;
			q.push(tup(y, x, nd));
		}
		nd = (d + 2 ^ 1) % 4;
		if (v[y][x][nd] > v[y][x][d] + 1) {
			v[y][x][nd] = v[y][x][d] + 1;
			q.push(tup(y, x, nd));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	int i, j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			cin >> a[i][j];
	cin >> sy >> sx >> sd;
	cin >> ey >> ex >> ed;
	sy--; sx--; sd--;
	ey--; ex--; ed--;
	bfs();
	cout << v[ey][ex][ed] << endl;
	return 0;
}
