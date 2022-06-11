#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, m, n, x, y, px, py;
	int r = 0;
	vector<vector<int>> a(1001, vector<int>(1001));
	queue<pair<int,int>> q;
	int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	cin>>m>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];

	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if (a[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	while(!q.empty()) {
		pair<int,int> p;
		p = q.front();
		q.pop();
		for (i=0;i<4;i++) {
			py = p.first;
			px = p.second;
			y = py + dir[i][0];
			x = px + dir[i][1];
			if (1 <= x && x <= m && 1 <= y && y<= n && !a[y][x]) {
				q.push(pair<int,int>(y,x));
				a[y][x] = a[py][px]+1;
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if (!a[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
			r = max(a[i][j], r);
		}
	}
	cout << r-1 << '\n';
	return 0;
}
