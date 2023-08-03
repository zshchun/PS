#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[101][101];
int visited[101][101];
int bitmap[101][101];
int W, H;
int sx = INF, sy = INF;
int ex = INF, ey = INF;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x, int d) {
	int i, nx, ny, nd;
//	if ((y == ey && x == ex)) return;
	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W || a[ny][nx])
			continue;
		if (d != i && d/2 == i/2)
			continue;
		nd = visited[y][x] + (d == i ? 0 : 1);
		if (visited[ny][nx] > nd) {
			visited[ny][nx] = nd;
			bitmap[ny][nx] = 0;
			dfs(ny, nx, i);
		} else if (visited[ny][nx] == nd && !(bitmap[ny][nx] & (1<<i))) {
			bitmap[ny][nx] |= (1<<i);
			dfs(ny, nx, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> W >> H;
	int i, j;
	string s;
//	fill(&visited[0][0], &visited[0][0]+101*101, INF);

	for (i=0;i<H;i++) {
		cin >> s;
		for (j=0;j<W;j++) {
			visited[i][j] = INF;
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

	visited[sy][sx] = 0;
	dfs(sy, sx, INF);

	cout << visited[ey][ex] - 1 << endl;

	return 0;
}
