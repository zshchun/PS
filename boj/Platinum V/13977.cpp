#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define MOD 1'000'000'007ull

ll M;
ll fact[4000001];

ll power(ll base, ll exp) {
	ll r = 1;
	while (exp) {
		if (exp & 1)
			r = r * base % MOD;
		exp /= 2;
		base = base * base % MOD;
	}
	return r;
}

ll mod_inv(ll n) {
	return power(n, MOD - 2ull);
}

ll solve(ll n, ll k) {
	return fact[n] * mod_inv(fact[k] * fact[n-k] % MOD) % MOD;
}

// Fermat's little theorem
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k, i;
	cin >> M;

	fact[0] = 1;
	for (i=1;i<=4000000;i++)
		fact[i] = (fact[i-1] * i) % MOD;

	for (i=0;i<M;i++) {
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}

	return 0;
}
