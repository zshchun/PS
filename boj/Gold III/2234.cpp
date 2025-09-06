#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int idx, cnt, mx1, mx2;
int visited[51][51];
int a[51][51];
vector<int> ans(1);

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = idx;
	cnt++;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[y][x] & (1<<i) || visited[ny][nx])
			continue;
		dfs(ny, nx);
	}
}

void break_wall(int y, int x, int ny, int nx, int i) {
	if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		return;
	int c1 = visited[y][x];
	int c2 = visited[ny][nx];
	if (c1 != c2)
		mx2 = max(ans[c1]+ans[c2], mx2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> m >> n;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			cin >> a[i][j];


	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (visited[i][j])
				continue;
			idx++;
			cnt = 0;
			dfs(i, j);
			mx1 = max(mx1, cnt);
			ans.push_back(cnt);
		}
	}

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			break_wall(i, j, i, j+1, 4);
			break_wall(i, j, i+1, j, 8);
		}
	}

	cout << idx << endl;
	cout << mx1 << endl;
	cout << mx2 << endl;

	return 0;
}
