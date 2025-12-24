#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
int N, M, T, ans;
int a[101][101];
int visited[2][101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
	int x, y, d, wp;
	queue<tup> q;
	q.push(tup(0, 0, 1, 0));
	visited[0][0][0] = 1;
	while (!q.empty()) {
		tie(y, x, d, wp) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (!wp && a[ny][nx] == 1) continue;
			if (visited[wp][ny][nx]) continue;
			visited[wp][ny][nx] = d + 1;
			q.push(tup(ny, nx, d+1, wp));
			if (a[ny][nx] == 2) {
				visited[1][ny][nx] = d + 1;
				q.push(tup(ny, nx, d+1, 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M >> T;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			cin >> a[i][j];
	bfs();
	if (visited[0][N-1][M-1] == 0 || visited[1][N-1][M-1] == 0)
		ans = max(visited[1][N-1][M-1], visited[0][N-1][M-1]);
	else
		ans = min(visited[1][N-1][M-1], visited[0][N-1][M-1]);

	if (ans == 0 || ans - 1 > T)
		cout << "Fail\n";
	else
		cout << ans - 1 << endl;
	return 0;
}
