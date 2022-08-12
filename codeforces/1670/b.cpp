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
		cin >> s >> m;
		vector<char> a(26);
		char c;
		for (i=0;i<m;i++) {
			cin >> c;
			a[c-'a'] = 1;
		}
		l = 0;
		ans = 0;
		for (i=0;i<n;i++) {
			if (a[s[i]-'a']) {
				ans = max(ans, l);
				l = 1;
			} else
				l++;
		}
		cout << ans << endl;
	}
	return 0;
}
