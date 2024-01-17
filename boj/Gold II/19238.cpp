#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;

int N, M, P, x, y, ans, cnt;
int a[20][20];
int visited[20][20];
int start[20][20];
pa goal[401];
vector<tup> nxt;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int bfs(int sy, int sx, int ey, int ex) {
	int cy, cx, nx, ny, i;
	queue<pa> q;
	q.push(pa(sy, sx));
	visited[sy][sx] = 1;
	nxt.clear();
	if (sy == ey && sx == ex)
		return 0;
	if (ey < 0 && ex < 0 && start[sy][sx])
		nxt.push_back(tup(0, sy, sx));

	while (!q.empty()) {
		tie(cy, cx) = q.front();
		q.pop();
		for (i=0;i<4;i++) {
			ny = cy + dy[i];
			nx = cx + dx[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= N || a[ny][nx] || visited[ny][nx])
				continue;
			if (ey < 0 && ex < 0 && start[ny][nx]) {
				nxt.push_back(tup(visited[cy][cx], ny, nx));
			} else if (ny == ey && nx == ex) {
				y = ny; x = nx;
				return visited[cy][cx];
			}
			visited[ny][nx] = visited[cy][cx] + 1;
			q.push(pa(ny, nx));
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, s, x1, y1, x2, y2, fuel;
	cin >> N >> M >> ans;

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
		}
	}

	cin >> y >> x;
	y--; x--;
	for (i=1;i<=M;i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		y1--; x1--; y2--; x2--;
		start[y1][x1] = i;
		goal[i] = pa(y2, x2);
	}

	while (cnt < M) {
		memset(visited, 0, sizeof(visited));
		bfs(y, x, -1, -1);
		if (nxt.empty()) {
			ans = -1;
			break;
		}
		sort(nxt.begin(), nxt.end());
		tie(fuel, y, x) = nxt[0];

		if (fuel == -1 || fuel > ans) {
			ans = -1;
			break;
		}
		ans -= fuel;
		s = start[y][x];
		start[y][x] = 0;

		memset(visited, 0, sizeof(visited));
		fuel = bfs(y, x, goal[s].first, goal[s].second);
		if (fuel == -1 || fuel > ans) {
			ans = -1;
			break;
		}
		ans += fuel;
		cnt++;
	}

	cout << ans << endl;

	return 0;
}
