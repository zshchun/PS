#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int,int> tup;
#define endl "\n"
#define INF 123456789

int k, w, h, ans = INF;
int a[200][200];
int visited[200][200][31];
int dx[] = { 2,  1,  2,  1, -1, -1, -2, -2, 0, 0, 1, -1, };
int dy[] = { 1,  2, -1, -2,  2, -2,  1, -1, 1, -1, 0, 0, };

void bfs() {
	int x, y, rk, c, ny, nx, i;
	queue<tup> q;
	q.push(make_tuple(0, 0, 0, 0));
	while (!q.empty()) {
		tie(x, y, rk, c) = q.front();
		q.pop();
		if (visited[y][x][rk] <= c)
			continue;
		visited[y][x][rk] = c;

		if (x == w-1 && y == h-1) {
			cout << c << endl;
			exit(0);
		}

		for (i=0;i<12;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h)
				continue;
			if (a[ny][nx])
				continue;
			if (i < 8 && rk < k) {
				q.push(tup(nx, ny, rk+1, c+1));
			} else if (i >= 8) {
				q.push(tup(nx, ny, rk, c+1));
			}
		}

	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> k >> w >> h;
	for (i=0;i<h;i++)
		for (j=0;j<w;j++)
			cin >> a[i][j];

	fill(&visited[0][0][0], &visited[0][0][0]+200*200*31, INF);

	bfs();

	cout << "-1\n";

	return 0;
}
