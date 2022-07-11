#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		ll x;
		cin >> x;
		ans = 0;
		ans |= 1<<(__builtin_ffs(x)-1);
		if (!(ans ^ x))
			ans |= 1<<(__builtin_ffs(~x)-1);
		cout << ans << endl;
	}
	return 0;
}
