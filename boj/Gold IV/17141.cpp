#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, ans = INF;
int a[51][51];
int visited[51][51];
vector<pa> virus;
queue<pa> q;
int empty_cell;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
	int y, x, nx, ny, i;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !a[ny][nx] && !visited[ny][nx]) {
				q.push(pa(ny, nx));
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				virus.push_back(pa(i, j));
				a[i][j] = 0;
			}
		}
	}

	for (k=1;k<(1<<virus.size());k++) {
		if (__builtin_popcount(k) != M) continue;
		int mx_count = 0;
		q = queue<pa>();
		memset(visited, 0, sizeof(visited));
		for (j=0;j<virus.size();j++) {
			if (k & (1<<j)) {
				q.push(virus[j]);
				visited[virus[j].first][virus[j].second] = 1;
			}
		}
		bfs();
		empty_cell = false;
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				if (a[i][j] != 0) continue;
				if (visited[i][j] == 0) {
					empty_cell = true;
					break;
				}
				mx_count = max(mx_count, visited[i][j] - 1);
			}
			if (empty_cell)
				break;
		}
		if (!empty_cell)
			ans = min(ans, mx_count);
	}
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
