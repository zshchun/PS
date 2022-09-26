#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll vert[1001][1001];
ll hori[1001][1001];
ll diag[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, i, j, k, l, mn, ans;
	N = 1;
	while (N != 0 && M != 0) {
		cin >> N >> M;
		if (N == 0 && M == 0) return 0;
		ans = 0;
		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				cin >> k;
				if (k == 0) {
					vert[i][j] = 0;
					hori[i][j] = 0;
					diag[i][j] = 0;
				} else {
					vert[i][j] = min(vert[i-1][j] + 1, vert[i-1][j-1]+1);
					hori[i][j] = min(hori[i][j-1] + 1, hori[i-1][j-1]+1);
					diag[i][j] = min({vert[i][j], hori[i][j], diag[i-1][j-1]+1});
				}
				ans = max(ans, diag[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
