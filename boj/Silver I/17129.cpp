#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m, sy, sx;
int a[3001][3001];
int visited[3001][3001];
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
	int i, y, x;
	queue<pa> q;
	q.push(pa(sy, sx));

	while (!q.empty()) {
		pa cur = q.front();
		q.pop();
		tie(y, x) = cur;
		if (a[y][x] > 2) {
			ans = visited[y][x];
			break;
		}
		for (i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || x < 0 || nx >= m || a[ny][nx] == 1 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> c;
			a[i][j] = c - '0';
			if (a[i][j] == 2) {
				sy = i; sx = j;
				a[i][j] = 1;
			}
		}
	}
	bfs();
	if (ans) {
		cout << "TAK\n";
		cout << ans << endl;
	} else {
		cout << "NIE\n";
	}
	return 0;
}
