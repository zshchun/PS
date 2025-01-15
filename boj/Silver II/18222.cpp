#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll solve(ll x) {
	if (x == 1)
		return 0;
	else if (x == 2)
		return 1;
	ll i = 1;
	while (i + i < x)
		i += i;
	return !solve(x - i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	cin >> k;
	cout << solve(k) << endl;
	return 0;
}
