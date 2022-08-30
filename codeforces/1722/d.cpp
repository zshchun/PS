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
		string s;
		cin >> s;
		ans = 0;
		vector<ll> a;
		for (i=0;i<n;i++) {
			if (s[i] == 'L') {
				ans += i;
			} else if (s[i] == 'R') {
				ans += (n-1-i);
			}
		}
		ll cnt = 0;

		for (i=0;i<n/2;i++) {
			if (s[i] == 'L') {
				ans = ans - i + (n - 1 -i);
				cout << ans << ' ';
				cnt++;
			}
			if (s[n-1-i] == 'R') {
				ans = ans - i + (n - 1 -i);
				cout << ans << ' ';
				cnt++;
			}
		}
		for (;cnt<n;cnt++) {
			cout << ans << ' ';
		}
		cout << endl;
	}
	return 0;
}
