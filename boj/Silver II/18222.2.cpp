#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll solve(ll x) {
	if (x == 0)
		return 0;
	if (x % 2)
		return !solve(x / 2);
	else
		return solve(x / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	cin >> k;
	cout << solve(k-1) << endl;
	return 0;
}
