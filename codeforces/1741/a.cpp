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
		string s, t;
		cin >> s >> t;
		ll l = 0;
		ll r = 0;
		if (s.back() == 'L') {
			l = 300;
			l += s.size() - 1;
		} else if (s.back() == 'M') {
			l = 200;
		} else if (s.back() == 'S') {
			l = 100;
			l += 60- (s.size() - 1);
		}
		if (t.back() == 'L') {
			r = 300;
			r += t.size() - 1;
		} else if (t.back() == 'M') {
			r = 200;
		} else if (t.back() == 'S') {
			r = 100;
			r += 60- (t.size() - 1);
		}
		if (l == r) {
			cout << "=\n";
		} else if (l < r) {
			cout << "<\n";
		} else {
			cout << ">\n";
		}
	}
	return 0;
}
