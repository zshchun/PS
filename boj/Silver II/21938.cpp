#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[1001][1001];
bool visited[1001][1001];
int n, m, t, ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = 1;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
		if (visited[ny][nx] || a[ny][nx] < t) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			for (k=0;k<3;k++) {
				cin >> x;
				a[i][j] += x;
			}
			a[i][j] /= 3;
		}
	}
	cin >> t;

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (a[i][j] >= t && !visited[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
