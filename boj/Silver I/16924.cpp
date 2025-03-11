#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

int n, m;
int a[101][101];
vector<tup> ans;

void dfs(int y, int x, int d) {
	if (y-d < 1 || y+d > n || x-d < 1 || x+d > m)
		return;

	if (!a[y-d][x] || !a[y+d][x] || !a[y][x-d] || !a[y][x+d])
		return;

	a[y][x] = a[y-d][x] = a[y+d][x] = a[y][x-d] = a[y][x+d] = 2;
	ans.push_back(tup(y, x, d));

	dfs(y, x, d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, y, s;
	char c;
	cin >> n >> m;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			cin >> c;
			if (c == '*')
				a[i][j] = 1;
		}
	}

	for (i=2;i<n;i++)
		for (j=2;j<m;j++)
			if (a[i][j])
				dfs(i, j, 1);

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i][j] == 1) {
				cout << "-1\n";
				return 0;
			}


	cout << ans.size() << endl;

	for (tup &t : ans) {
		tie(y, x, s) = t;
		cout << y << ' ' << x << ' ' << s << endl;
	}
	return 0;
}
