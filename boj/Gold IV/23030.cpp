#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll T, U1, U2, V1, V2;
optional<pa> trans[11][51];
ll visited[11][51];
ll stations[11];

void bfs() {
	queue<pa> q;
	q.push(pa(U1, U2));
	ll i, j;
	visited[U1][U2] = 0;
	while (!q.empty()) {
		tie(i, j) = q.front();
		q.pop();
		if (j-1 >= 1 && visited[i][j-1] > visited[i][j] + 1) {
			q.push(pa(i, j-1));
			visited[i][j-1] = visited[i][j] + 1;
		}
		if (j+1 <= stations[i] && visited[i][j+1] > visited[i][j] + 1) {
			q.push(pa(i, j+1));
			visited[i][j+1] = visited[i][j] + 1;
		}
		if (trans[i][j]) {
			ll x, y;
			tie(x, y) = *trans[i][j];
			if (visited[x][y] > visited[i][j] + T) {
				q.push(pa(x, y));
				visited[x][y] = visited[i][j] + T;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, K, i;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> stations[i];
	}
	cin >> M;
	ll P1, P2, Q1, Q2;
	for (i=0;i<M;i++) {
		cin >> P1 >> P2 >> Q1 >> Q2;
		trans[P1][P2] = pa(Q1, Q2);
		trans[Q1][Q2] = pa(P1, P2);
	}
	cin >> K;
	for (i=0;i<K;i++) {
		memset(visited, 0x3f, sizeof(visited));
		cin >> T >> U1 >> U2 >> V1 >> V2;
		bfs();
		cout << visited[V1][V2] << endl;
	}
	return 0;
}
