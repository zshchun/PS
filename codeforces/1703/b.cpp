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
		vector<ll> a(26);
		string s;
		cin >> s;
		for (char &c : s) {
			if (a[c-'A']) {
				ans++;
			} else {
				a[c-'A'] = 1;
				ans += 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
