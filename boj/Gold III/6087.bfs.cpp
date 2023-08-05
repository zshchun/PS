#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

int a[101][101];
int visited[101][101][4];
int W, H;
int sx = INF, sy = INF;
int ex = INF, ey = INF;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	int i, y, x, d, nx, ny, nd;
	queue<tup> q;
	visited[sy][sx][0] = 0;
	visited[sy][sx][1] = 0;
	visited[sy][sx][2] = 0;
	visited[sy][sx][3] = 0;
	q.push(make_tuple(sy, sx, INF));

	while (!q.empty()) {
		tie(y, x, d) = q.front();
		q.pop();

		for (i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W || a[ny][nx])
				continue;
			if (d != i && d/2 == i/2)
				continue;
			int dir = d == INF ? i : d;
			nd = visited[y][x][dir] + (dir == i ? 0 : 1);
			if (visited[ny][nx][i] > nd) {
				visited[ny][nx][i] = nd;
				q.push(tup(ny, nx, i));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> W >> H;
	int i, j;
	string s;

	for (i=0;i<H;i++) {
		cin >> s;
		for (j=0;j<W;j++) {
			visited[i][j][0] = INF;
			visited[i][j][1] = INF;
			visited[i][j][2] = INF;
			visited[i][j][3] = INF;
			if (s[j] == '*') {
				a[i][j] = 1;
			} else if (s[j] == 'C') {
				if (sx == INF) {
					sy = i;
					sx = j;
				} else {
					ey = i;
					ex = j;
				}
			}
		}
	}

	bfs();

	cout << min({visited[ey][ex][0], visited[ey][ex][1], visited[ey][ex][2], visited[ey][ex][3]}) << endl;


	return 0;
}
