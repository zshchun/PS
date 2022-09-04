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

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, n, k, r, c, i, j, d;
	cin >> T;
	while(T--) {
		cin >> n >> k >> r >> c;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if ((i+j)%k == (r+c)%k) {
					cout << 'X';
				} else {
					cout << '.';
				}
			}
			cout << endl;
		}
	}
	return 0;
}
