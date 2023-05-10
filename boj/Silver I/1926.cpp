#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a[501][501];
int visited[501][501];
int ans, cnt, max_cnt;

void dfs(int y, int x) {
	int i;
	visited[y][x] = 1;
	cnt++;
	for (i=0;i<4;i++) {
		if (y+dy[i] < 0 || y+dy[i] >= n)
			continue;
		if (x+dx[i] < 0 || x+dx[i] >= m)
			continue;
		if (!a[y+dy[i]][x+dx[i]] || visited[y+dy[i]][x+dx[i]])
			continue;
		dfs(y+dy[i], x+dx[i]);
	}
}

int main() {
	int i, j;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (a[i][j] && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				if (cnt > max_cnt)
					max_cnt = cnt;
				ans++;
			}
		}
	}
	cout << ans << endl;
	cout << max_cnt << endl;

	return 0;
}
