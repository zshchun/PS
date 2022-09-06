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
		cin >> n >> m;
		ans = 0;
		vector<ll> a;
		if (n > m) {
			cout << "No\n";
			continue;
		}
		if (n%2 == 1) {
			cout << "Yes\n";
			for (i=0;i<n-1;i++) {
				cout << "1 ";
			}
			cout << m-n+1 << endl;
		} else if (m%2 == 0) {
			cout << "Yes\n";
			for (i=0;i<n-2;i++) {
				cout << "1 ";
			}
			j = (m-(n-2)) / 2;
			cout << j << " " << j << endl;
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
