#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int,int> tup;
#define endl "\n"
#define INF 123456789
int n, k, r, cnt, ans;
int a[101][101];
int visited[101][101];
int color[101*101];
// flood fill

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
#define COW 1
set<tup> wall;

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
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (wall.find(tup(y, x, ny, nx)) != wall.end())
				continue;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, r1, c1, r2, c2;
	cin >> n >> k >> r;
	for (i=0;i<r;i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		wall.insert(tup(r1, c1, r2, c2));
		wall.insert(tup(r2, c2, r1, c1));
	}
	vector<pa> cow;
	for (i=0;i<k;i++) {
		cin >> r1 >> c1;
		r1--; c1--;
		a[r1][c1] = COW;
		cow.push_back(pa(r1, c1));
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
