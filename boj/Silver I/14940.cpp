#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int a[1001][1001];
int visited[1001][1001];
int N, M, X, Y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
	queue<pa> q;
	q.push(pa(Y, X));
	int y, x;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= M || a[ny][nx] != 1 || visited[ny][nx] != -1)
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
	for (i=0;i<N;i++)
		for (j=0;j<M;j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				Y = i;
				X = j;
			} else if (a[i][j] == 1) {
				visited[i][j] = -1;
			}
		}

	bfs();

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
