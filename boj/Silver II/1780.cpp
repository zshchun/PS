#include <bits/stdc++.h>
using namespace std;
int m[2188][2188];
int ans[3];
void solve(int ys, int ye, int xs, int xe) {
	int i, j, v;
	bool same = true;
	v = m[ys][xs];
	for (i=ys;i<=ye && same;i++) {
		for (j=xs;j<=xe;j++) {
			if (m[i][j] != v) {
				same = false;
				break;
			}
		}
	}
	if (same) {
		ans[v+1]++;
	} else {
		int d = (xe-xs+1) / 3;
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				solve(ys+d*i, ys+d*(i+1)-1, xs+d*j, xs+d*(j+1)-1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			cin >> m[i][j];
		}
	}

	solve(1, n, 1, n);
	cout << ans[0] << "\n";
	cout << ans[1] << "\n";
	cout << ans[2] << "\n";
	return 0;
}
