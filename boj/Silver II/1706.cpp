#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

vector<string> ans;
char a[21][21];
bool visited[21][21][2];
int r, c;

void dfs(int y, int x, int d, string s) {
	if (visited[y][x][d]) return;
	visited[y][x][d] = 1;

	if (y >= r || x >= c || a[y][x] == '#') {
		if (s.size() >= 2)
			ans.push_back(s);
		return;
	}
	if (d == 0)
		dfs(y, x+1, d, s + a[y][x]);
	else
		dfs(y+1, x, d, s + a[y][x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> r >> c;
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			cin >> a[i][j];
	
	for (i=0;i<r;i++) {
		for (j=0;j<c;j++) {
			if (a[i][j] == '#')
				continue;
			if (!visited[i][j][0])
				dfs(i, j, 0, "");
			if (!visited[i][j][1])
				dfs(i, j, 1, "");
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.front() << endl;

	return 0;
}
