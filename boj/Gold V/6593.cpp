#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int L, R, C;
int a[31][31][31];
int visited[31][31][31];
int dx[6] = {0,  0,  1, -1,  0,  0};
int dy[6] = {1, -1,  0,  0,  0,  0};
int df[6] = {0,  0,  0,  0,  1, -1};
int sf, sx, sy, ef, ex, ey;

void bfs() {
	queue<tup> q;
	q.push(tup(sf, sy, sx));
	visited[sf][sy][sx] = 1;
	int f, y, x, nf, ny, nx;

	while (!q.empty()) {
		tie(f, y, x) = q.front();
		q.pop();
		if (f == ef && ey == y && ex == x)
			break;
		for (int i=0;i<6;i++) {
			nf = f + df[i];
			ny = y + dy[i];
			nx = x + dx[i];
			if (nf < 0 || nf >= L || ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue;
			if (a[nf][ny][nx] || visited[nf][ny][nx])
				continue;
			visited[nf][ny][nx] = visited[f][y][x] + 1;
			q.push(tup(nf, ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	char c;

	while (1) {
		cin >> L >> R >> C;
		if (!L && !R && !C)
			break;
		memset(visited, 0, sizeof(visited));
		for (k=0;k<L;k++) {
			for (i=0;i<R;i++) {
				for (j=0;j<C;j++) {
					cin >> c;
					if (c == 'S') {
						sf = k; sy = i; sx = j;
					} else if (c == 'E') {
						ef = k; ey = i; ex = j;
					} else if (c == '#') {
						a[k][i][j] = 1;
					} else if (c == '.') {
						a[k][i][j] = 0;
					}
				}
			}
		}
		bfs();
		if (visited[ef][ey][ex]) {
			cout << "Escaped in " << visited[ef][ey][ex] - 1 << " minute(s).\n";
		} else {
			cout << "Trapped!\n";
		}
	}
	return 0;
}
