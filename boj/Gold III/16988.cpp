#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll n, m, cnt, hole;
vector<pa> hs;
ll h[20][20];
ll a[20][20];
bool visited[20][20];
ll dx[4] = { 0, 0, 1, -1 };
ll dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	ll i, nx, ny;

	if (a[x][y] == 0) {
		hole++;
		return;
	}

	if (visited[x][y])
		return;
	visited[x][y] = 1;

	if (a[x][y] < 2)
		return;


	cnt++;
	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, x1, x2, y1, y2, sum;
	ll ans = 0;
	cin >> n >> m;

	vector<pa> holes;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				holes.push_back(pa(i, j));
		}
	}

	for (ll p1=0;p1<holes.size();p1++) {
		for (ll p2=p1+1;p2<holes.size();p2++) {
			tie(x1, y1) = holes[p1];
			tie(x2, y2) = holes[p2];
			a[x1][y1] = 1;
			a[x2][y2] = 1;
			memset(visited, 0, sizeof(visited));

			sum = 0;

			for (i=0;i<n;i++) {
				for (j=0;j<m;j++) {
					if (a[i][j] == 2 && !visited[i][j]) {
						hole = 0;
						cnt = 0;
						dfs(i, j);
						if (hole == 0) {
							sum += cnt;
						}
					}
				}
			}
			if (sum > ans)
				ans = sum;
			a[x1][y1] = 0;
			a[x2][y2] = 0;
		}
	}

	cout << ans << endl;

	return 0;
}
