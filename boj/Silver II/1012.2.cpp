#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[2500][2500];
bool visited[2500][2500];
int M, N, K;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sy, int sx) {
	int i, x, y;
	queue<pa> q;
	q.push(pa(sy, sx));
	visited[sy][sx] = 1;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && a[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push(pa(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, x, y, ans;
	cin >> T;
	while (T--) {
		ans = 0;
		memset(visited, 0, sizeof(visited));
		memset(a, 0, sizeof(a));
		cin >> M >> N >> K;
		for (i=0;i<K;i++) {
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				if (a[i][j] && !visited[i][j]) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
