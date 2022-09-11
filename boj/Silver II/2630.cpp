#include <bits/stdc++.h>
using namespace std;
int color[2];
int a[128][128];
void solve(int y, int x, int l) {
	int i, j;
	bool same = true;
	for (i=y;i<y+l && same;i++)
		for (j=x;j<x+l && same;j++)
			if (a[i][j] != a[y][x])
				same = false;
	if (same)
		color[a[y][x]]++;
	else {
		int h = l/2;
		solve(y, x, h);
		solve(y, x+h, h);
		solve(y+h, x, h);
		solve(y+h, x+h, h);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	cin >> n;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			cin >> a[i][j];
	solve(0, 0, n);
	cout << color[0] << "\n";
	cout << color[1] << "\n";

	return 0;
}
