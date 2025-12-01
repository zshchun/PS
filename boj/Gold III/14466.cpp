#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, k, r, cnt, ans;
int a[202][202];
int visited[202][202];
int color[202*202];
// flood fill

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
#define COW 1
#define WALL 2

void bfs(int cy, int cx) {
	int x, y;
	queue<pa> q;
	q.push(pa(cy, cx));
	cnt++;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = cnt;
		if (a[y][x] == COW)
			color[cnt]++;
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n*2-1 || ny < 0 || ny >= n*2-1)
				continue;
			if (a[ny][nx] == WALL)
				continue;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, r1, c1, r2, c2, ny, nx;
	cin >> n >> k >> r;
	for (i=1;i<n*2-1;i+=2)
		for (j=1;j<n*2-1;j+=2)
			a[i][j] = WALL;
	for (i=0;i<r;i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		r1 *= 2; r2 *= 2;
		c1 *= 2; c2 *= 2;
		ny = (r1 + r2) / 2;
		nx = (c1 + c2) / 2;
		a[ny][nx] = WALL;
	}
	vector<pa> cow;
	for (i=0;i<k;i++) {
		cin >> r1 >> c1;
		r1--; c1--;
		a[r1*2][c1*2] = COW;
		cow.push_back(pa(r1*2, c1*2));
	}
	for (auto &[y, x] : cow) {
		if (visited[y][x])
			continue;
		bfs(y, x);
		for (auto &[ny, nx] : cow)
			if (!visited[ny][nx])
				ans += color[cnt];
	}

	cout << ans << endl;
	return 0;
}
