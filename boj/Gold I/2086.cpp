#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD 1000000000
map<ll,ll> dp;

ll fibo(ll n) {
	ll a, b;
	if (n == 0)
		return 0;
	else if (n <= 2)
		return 1;
	if (!dp.count(n)) {
		if (n & 1) {
			a = fibo((n+1)/2);
			b = fibo((n+1)/2-1);
			dp[n] = (a * a + b * b) % MOD;
		} else {
			a = fibo(n/2-1);
			b = fibo(n/2);
			dp[n] = ((2 * a + b) * b) % MOD;
		}
	}

	return dp[n];
}

// d'Ocagne's identity
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	cout << (fibo(b+2) - fibo(a+1) + MOD) % MOD << endl;
	return 0;
}
