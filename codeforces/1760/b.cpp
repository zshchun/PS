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
		cin >> s;
		ans = 0;
		for (i=0;i<n;i++) {
			ans = max((ll)s[i]-'a'+1, ans);
		}
		cout << ans << endl;
	}
	return 0;
}
