#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567ULL
ll n, m, ans = INF;
ll a[101][101];

// floyd warshall
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, x;
	cin >> n >> m;
	fill_n(&a[0][0], 101*101, INF);
	pa p;

	for (i=0;i<=n;i++)
		a[i][i] = 0;

	for (i=0;i<m;i++) {
		cin >> j >> k;
		a[j][k] = 1;
		a[k][j] = 1;
	}

	for (k=1;k<=n;k++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}

	for (i=1;i<=n;i++) {
		for (j=i+1;j<=n;j++) {
			x = 0;
			for (k=1;k<=n;k++)
				x += min(a[k][i], a[k][j]) * 2;
			if (ans > x) {
				ans = x;
				p = pa(i, j);
			}
		}
	}

	cout << p.first << ' ' << p.second << ' ' << ans << endl;
	return 0;
}
