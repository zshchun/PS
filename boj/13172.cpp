#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007
ll power(int base, int exp, int mod) {
	ll r = 1, b = base, e = exp;
	while (e) {
		if (e & 1)
			r = r * b % mod;
		e /= 2;
		b = b * b % mod;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll ans = 0;
	ll i, M, N, S;
	cin >> M;
	for (i=0;i<M;i++) {
		cin >> N >> S;
		ans = (ans + (S * power(N, MOD-2, MOD))) % MOD;
	}
	cout << ans << '\n';
	return 0;
}

