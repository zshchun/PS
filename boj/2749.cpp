#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<ll>> matrix;

matrix operator*(matrix &a, matrix &b) {
	matrix result(2, vector<ll>(2));
	int i, j, k;
	for (i=0;i<2;i++)
		for (k=0;k<2;k++)
			for (j=0;j<2;j++) {
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= 1000000;
			}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll e;
	matrix b = {{1, 1}, {1, 0}};
	matrix ans = {{1, 0}, {0, 1}};
	cin >> e;
	while (e) {
		if (e & 1)
			ans = ans * b;
		b = b * b;
		e /= 2;
	}
	cout << ans[0][1] << '\n';
	return 0;
}

