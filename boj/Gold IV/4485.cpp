#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, ans;
int a[125][125];
int visited[125][125];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
	int nx, ny, x, y;
	queue<pa> q;
	q.push(pa(0, 0));
	visited[0][0] = a[0][0];
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		if (y == N-1 && x == N-1) {
		}
		for (int i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited[ny][nx] > visited[y][x] + a[ny][nx]) {
				visited[ny][nx] = visited[y][x] + a[ny][nx];
				q.push(pa(ny, nx));
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, idx = 1;
	while (1) {
		cin >> N;
		if (N == 0)
			break;

		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				cin >> a[i][j];
			}
		}

		fill(&visited[0][0], &visited[0][0]+125*125, INF);

		bfs();

		cout << "Problem " << idx << ": " << visited[N-1][N-1] << endl;
		idx++;
	}

	return 0;
}
