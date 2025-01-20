#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
#define UNUSED 0
#define USED 1

int n, m, hx, hy, ex, ey;
bool a[1001][1001];
int visited[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int hy, int hx) {
	queue<tup> q;
	q.push(tup(hy, hx, 0));
//	visited[hy][hx][USED] = 0;
	visited[hy][hx][UNUSED] = 0;
	int x, y, used, nx, ny;

	while (!q.empty()) {
		tie(y, x, used) = q.front();
		q.pop();
		if (y == ey && x == ex)
			break;
		for (int i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (a[ny][nx] == 0 && visited[ny][nx][used] > visited[y][x][used] + 1) {
				q.push(tup(ny, nx, used));
				visited[ny][nx][used] = visited[y][x][used] + 1;
			}
			if (used == UNUSED) {
				if (a[ny][nx] == 1 && visited[ny][nx][USED] > visited[y][x][UNUSED] + 1) {
					q.push(tup(ny, nx, USED));
					visited[ny][nx][USED] = visited[y][x][UNUSED] + 1;
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, j, ans;
	fill_n(&visited[0][0][0], 1001*1001*2, INF);

	cin >> n >> m >> hy >> hx >> ey >> ex;
	hx--; hy--; ex--; ey--;

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}

	bfs(hy, hx);

	ans = min(visited[ey][ex][USED], visited[ey][ex][UNUSED]);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	
	return 0;
}
