#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"

int n, m;
int ans[1001*1001];
int visited[1001][1001];
int a[1001][1001];
int idx;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// flood fill
void bfs(int cy, int cx) {
	int x, y, cnt = 1;
	idx++;
	queue<pa> q;
	q.push(pa(cy, cx));
	visited[cy][cx] = idx;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] || visited[ny][nx])
				continue;
			visited[ny][nx] = idx;
			cnt++;
			q.push(pa(ny, nx));
		}
	}
	ans[idx] = cnt;
}

int solve(int y, int x) {
	int ret = 1;
	set<int> s;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx])
			continue;
		s.insert(visited[ny][nx]);
	}
	for (int i : s)
		ret += ans[i];
	return ret % 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> n >> m;

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (!a[i][j] && !visited[i][j])
				bfs(i, j);

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (a[i][j])
				cout << solve(i, j);
			else
				cout << "0";
		}
		cout << endl;
	}

	return 0;
}
