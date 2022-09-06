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
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		char c;
		ll depth = 0;
		ll last = -1;
		for (i=0;i<n*2;i++) {
			cin >> c;
			if (c == '(') {
				if (last != depth) {
					ans++;
				}
				depth++;
			} else if (c == ')') {
				depth--;
				last = depth;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
