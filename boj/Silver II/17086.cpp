#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[51][51];
int visited[51][51];
int ans;
int N, M;
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

void bfs(int sy, int sx) {
	int i, x, y;
	queue<pa> q;
	q.push(pa(sy, sx));
	visited[sy][sx] = 0;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (i=0;i<sizeof(dx)/sizeof(dx[0]);i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] <= visited[y][x]+1)
				continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
		}
	}

	memset(visited, 0x7f, sizeof(visited));
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (a[i][j]) {
				bfs(i, j);
			}
		}
	}

	ans = 0;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (visited[i][j] > ans)
				ans = visited[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}
