#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,bool> P;
typedef tuple<int,int,bool> T;

int m[1001][1001];
int visited[1001][1001];
int visited2[1001][1001];
int N, M;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int starty, int startx) {
	queue<T> q;
	int curx, cury;
	bool wall;
	q.push(T(starty, startx, 0));
	visited[starty][startx] = 1;
	visited2[starty][startx] = 1;
	while (!q.empty()) {
		tie(cury, curx, wall) = q.front();
		q.pop();
		if (cury == N-1 && curx == M-1) break;
		for (auto &p : dir) {
			int y = cury + p[0];
			int x = curx + p[1];
			if (x >= 0 && x < M && y >= 0 && y < N && ((wall == 0 && !visited[y][x]) || (wall == 1 && !m[y][x] && !visited2[y][x]))) {
				if (m[y][x]) {
					visited2[y][x] = visited[cury][curx] + 1;
					q.push(T(y, x, 1));
				} else if (wall) {
					visited2[y][x] = visited2[cury][curx] + 1;
					q.push(T(y, x, 1));
				} else {
					visited[y][x] = visited[cury][curx] + 1;
					visited2[y][x] = visited[cury][curx] + 1;
					q.push(T(y, x, 0));
				}
			}
		}
	}
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
	bfs(0, 0);
	if (!visited[N-1][M-1] && !visited2[N-1][M-1])
		cout << "-1\n";
	else
		cout << max(visited[N-1][M-1], visited2[N-1][M-1]) << '\n';
	return 0;
}
