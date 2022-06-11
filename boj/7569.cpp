#include <bits/stdc++.h>
using namespace std;
int d[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int a[101][101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, M, N, H;
	queue<tuple<int,int,int>> q;
	cin >> M >> N >> H;
	for (i=1;i<=H;i++) {
		for (j=1;j<=N;j++) {
			for (k=1;k<=M;k++) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 1)
					q.push(make_tuple(i, j, k));

			}
		}
	}
	tuple<int,int,int> t;
	int x, y, z, ans = 0;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		z = get<0>(t);
		y = get<1>(t);
		x = get<2>(t);
		for (i=0;i<6;i++) {
			if (x+d[i][0] > 0 && x+d[i][0] <= M && y+d[i][1] > 0 && y+d[i][1] <= N && z+d[i][2] > 0 && z+d[i][2] <= H && !a[z+d[i][2]][y+d[i][1]][x+d[i][0]]) {
				q.push(make_tuple(z+d[i][2], y+d[i][1], x+d[i][0]));
				a[z+d[i][2]][y+d[i][1]][x+d[i][0]] = a[z][y][x] + 1;
			}
		}
	}
	for (i=1;i<=H;i++) {
		for (j=1;j<=N;j++) {
			for (k=1;k<=M;k++) {
				if (!a[i][j][k]) {
					cout << "-1\n";
					return 0;
				}
				ans = max(ans, a[z][y][x]);
			}
		}
	}
	cout << ans -1 << '\n';
	return 0;
}
