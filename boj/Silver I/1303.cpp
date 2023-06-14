#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll n, m, ans[2];
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
ll visited[101][101];
ll a[101][101];

ll dfs(ll y, ll x, ll color) {
	ll c = 0, i, j;
	if (visited[y][x])
		return 0;
	visited[y][x] = 1;
	c++;

	for (i=0;i<4;i++) {
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (color != a[ny][nx])
			continue;
		c += dfs(ny, nx, color);
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll sum, i, j;
	char ch;
	cin >> m >> n;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> ch;
			if (ch == 'B')
				a[i][j] = 1;
		}
	}

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (!visited[i][j]) {
				sum = dfs(i, j, a[i][j]);
				if (a[i][j])
					ans[1] += sum * sum;
				else
					ans[0] += sum * sum;
			}

		}
	}

	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
