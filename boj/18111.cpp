#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, B, i, j, up=0, dn=1<<30, ans = 1<<30, f, ansf=0, b, s;
	cin >> N >> M >> B;

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
			if (a[i][j] < dn)
				dn = a[i][j];
			if (a[i][j] > up)
				up = a[i][j];
		}
	}
	for (f=dn;f<=up;f++) {
		s = 0;
		b = B;
		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				if (a[i][j] > f) {
					s += (a[i][j] - f) * 2;
					b += (a[i][j] - f);
				}
			}
		}
		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				if (a[i][j] < f) {
					s += f - a[i][j];
					b -= f - a[i][j];
				}
			}
		}
		if (b < 0) continue;
		if (s < ans || (s == ans && f > ansf)) {
			ans = s;
			ansf = f;
		}
	}
	cout << ans << " " << ansf << "\n";
	return 0;
}
