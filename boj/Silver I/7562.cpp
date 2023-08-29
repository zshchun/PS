#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int l, sy, sx, ey, ex;
int visited[301][301];
int dx[8] = {-2, -1,  1,  2, 1, 2, -1, -2};
int dy[8] = {-1, -2, -2, -1, 2, 1,  2,  1};

void bfs() {
	queue<pa> q;
	int y, x, ny, nx;

	q.push(pa(sy, sx));
	visited[sy][sx] = 1;

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		
		if (y == ey && x == ex)
			break;

		for (int i=0;i<8;i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= l || nx >= l || visited[ny][nx])
				continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> l >> sy >> sx >> ey >> ex;
		memset(visited, 0, sizeof(visited));
		bfs();
		cout << visited[ey][ex] - 1 << endl;
	}
	return 0;
}
