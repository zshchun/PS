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

inline ll digit(ll x) {
	if (x < 10) return 1;
	if (x < 100) return 2;
	if (x < 1000) return 3;
	if (x < 10000) return 4;
	if (x < 100000) return 5;
	if (x < 1000000) return 6;
	if (x < 10000000) return 7;
	if (x < 100000000) return 8;
	if (x < 1000000000) return 9;
}
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		multiset<ll> a;
		multiset<ll> b;
		for (i=0;i<n;i++) {
			cin >> j;
			a.insert(j);
		}
		for (i=0;i<n;i++) {
			cin >> j;
			b.insert(j);
		}
		while (!a.empty()) {
			auto it1 = a.end();
			auto it2 = b.end();
			it1--; it2--;
			if (*it1 == *it2) {
				a.erase(it1);
				b.erase(it2);
				continue;
			}
			if (*it1 > *it2) {
				a.insert(digit(*it1));
				a.erase(it1);
			} else {
				b.insert(digit(*it2));
				b.erase(it2);
			}
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
