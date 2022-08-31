#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;
ll a[1002][1002];
ll sum[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, k, z, l, r, q;
	cin >> T;
	while(T--) {
		cin >> n >> q;
		memset(a, 0, sizeof(a));
		for (i=0;i<n;i++) {
			cin >> l >> r;
			a[l][r] += l * r;
		}
		for (i=1;i<=1000;i++) {
			for (j=1;j<=1000;j++) {
				sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
			}
		}
		for (i=0;i<q;i++) {
			ll y, x, Y, X;
			cin >> y >> x >> Y >> X;
			Y--; X--;
			cout << sum[Y][X] - sum[y][X] - sum[Y][x] + sum[y][x] << endl;
		}
	}
	return 0;
}
