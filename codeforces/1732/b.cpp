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
		cin >> n;
		string s;
		ans = 0;
		cin >> s;
		reverse(s.begin(), s.end());
		for (i=1;i<n;i++) {
			if (s[i-1] != s[i])
				ans++;
		}
		if (s[n-1] == '0' && ans > 0)
			ans--;
		cout << ans << endl;
	}
	return 0;
}
