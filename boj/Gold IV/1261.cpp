#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll N, M;
ll m[101][101];
ll visited[101][101];
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
void bfs() {
	ll y, x;
	queue<pa> q;
	q.push(pa(0, 0));
	visited[0][0] = 0;
	while (!q.empty()) {
		pa cur = q.front();
		q.pop();
		y = cur.first;
		x = cur.second;
		if (y == N-1 && x == M-1)
			continue;

		for (ll i=0;i<4;i++) {
			ll ny = y+dy[i];
			ll nx = x+dx[i];
			if (ny >= N || ny < 0 || nx < 0 || nx >= M)
				continue;

			ll next = visited[y][x] + m[ny][nx];
			if (next < visited[ny][nx]) {
				q.push(pa(ny, nx));
				visited[ny][nx] = next;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> M >> N;
	char c;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			m[i][j] = c - '0';
		}
	}

	fill(&visited[0][0], &visited[0][0]+101*101, INF);
	bfs();
	cout << visited[N-1][M-1] << endl;

	return 0;
}
