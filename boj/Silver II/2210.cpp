#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[5][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
unordered_set<int> ans;

void dfs(int y, int x, int c, int n) {
	if (n == 6) {
		ans.insert(c);
		return;
	}

	int i, nx, ny;
	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;
		dfs(ny, nx, c*10+a[ny][nx], n+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	for (i=0;i<5;i++)
		for (j=0;j<5;j++)
			cin >> a[i][j];

	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			dfs(i, j, 0, 0);
		}
	}

	cout << ans.size() << endl;
	
	return 0;
}
