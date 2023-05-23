#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll N, M;
ll m[101][101];
ll dist[101][101];
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

void dijkstra() {
	ll y, x;
	priority_queue<pa, vector<pa>, greater<pa>> pq;
	pq.push(pa(0, 0));
	dist[0][0] = 0;
	while (!pq.empty()) {
		pa cur = pq.top();
		pq.pop();
		y = cur.first;
		x = cur.second;

		for (ll i=0;i<4;i++) {
			ll ny = y+dy[i];
			ll nx = x+dx[i];
			if (ny >= N || ny < 0 || nx < 0 || nx >= M)
				continue;

			ll next = dist[y][x] + m[ny][nx];
			if (next < dist[ny][nx]) {
				pq.push(pa(ny, nx));
				dist[ny][nx] = next;
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

	fill(&dist[0][0], &dist[0][0]+101*101, INF);
	dijkstra();
	cout << dist[N-1][M-1] << endl;

	return 0;
}
