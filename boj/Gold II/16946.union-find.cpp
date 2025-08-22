#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int n, m;
bool visited[1001][1001];
int a[1001][1001];
int ans[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int p[1001*1001];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void _union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a > b) swap(a, b);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] || visited[ny][nx])
			continue;
		_union(y*m+x, ny*m+nx);
		dfs(ny, nx);
	}
}

void merge(int y, int x) {
	ans[y][x] = 1;
	set<int> s;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx])
			continue;
		s.insert(find(ny*m+nx));
	}
	for (int z: s)
		ans[y][x] -= p[z];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> n >> m;
	fill_n(p, 1001*1001, -1);
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (!a[i][j])
				dfs(i, j);

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (a[i][j])
				merge(i, j);
			cout << ans[i][j] % 10;
		}
		cout << endl;
	}

	return 0;
}
