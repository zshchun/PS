#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,bool> P;
typedef tuple<int,int,bool> T;

int m[1001][1001];
int visited[1001][1001][2];
int N, M;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(int starty, int startx) {
	queue<T> q;
	int curx, cury;
	bool wall;
	q.push(T(starty, startx, 0));
	visited[starty][startx][0] = 1;
	while (!q.empty()) {
		tie(cury, curx, wall) = q.front();
		q.pop();
		if (cury == N-1 && curx == M-1) return visited[cury][curx][wall];
		for (auto &p : dir) {
			int y = cury + p[0];
			int x = curx + p[1];
			if (x < 0 || x >= M || y < 0 || y >= N) continue;
			if (wall == 0 && m[y][x]) {
				visited[y][x][1] = visited[cury][curx][wall] + 1;
				q.push(T(y, x, 1));
			} else if (!m[y][x] && !visited[y][x][wall]) {
				visited[y][x][wall] = visited[cury][curx][wall] + 1;
				if (!wall)
					visited[y][x][1] = visited[cury][curx][wall] + 1;
				q.push(T(y, x, wall));
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M;
	string s;
	for (i=0;i<N;i++) {
		cin >> s;
		for (j=0;j<M;j++) {
			m[i][j] = s[j] - '0';
		}
	}
	cout << bfs(0, 0) << '\n';
	return 0;
}
