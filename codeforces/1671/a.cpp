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
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		string s;
		cin >> s;
		ll p = 1;
		bool ok = true;
		for (i=1;i<s.size();i++) {
			if (s[i-1] == s[i]) {
				p++;
			} else {
				if (p < 2) {
					ok = false;
					break;
				}
				p = 1;
			}
		}

		if (ok && s.size() >= 2 && p >= 2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
