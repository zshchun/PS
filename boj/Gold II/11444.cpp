#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

typedef vector<vector<ll> > M;
M operator*(M& lhs, M&rhs) {
	int i, j, k;
	M res(2, vector<ll>(2));
	for (i=0;i<2;i++) {
		for (k=0;k<2;k++) {
			for (j=0;j<2;j++) {
				res[i][j] += lhs[i][k] * rhs[k][j];
				if (res[i][j] > 1000000007)
					res[i][j] %= 1000000007;
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll e;
	cin >> e;
	M ans = {{1, 0}, {0, 1}};
	M b = {{1, 1}, {1, 0}};
	while (e) {
		if (e & 1)
			ans = ans * b;
		e >>= 1;
		b = b * b;
	}
	cout << ans[0][1] << '\n';
	return 0;
}
