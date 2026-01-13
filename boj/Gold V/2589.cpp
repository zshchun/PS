#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int R, C, ans;
bool a[51][51];
bool visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sy, int sx) {
	queue<tup> q;
	q.push(tup(sy, sx, 0));
	visited[sy][sx] = 1;
	while (!q.empty()) {
		auto [y, x, d] = q.front();
		q.pop();
		ans = max(ans, d);

		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= C || ny >= R || !a[ny][nx] || visited[ny][nx])
				continue;
			visited[ny][nx] = 1;
			q.push(tup(ny, nx, d + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> R >> C;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> c;
			if (c == 'L')
				a[i][j] = 1;
		}
	}
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (a[i][j]) {
				memset(visited, 0, sizeof(visited));
				bfs(i, j);
			}
		}
	}
	cout << ans << endl;

	return 0;
}
