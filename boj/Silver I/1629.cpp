#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow(ll base, ll exp, ll mod) {
	ll b = base, e=exp, r=1;
	while (e) {
		if (e & 1)
			r = r * b % mod;
		e >>= 1;
		b = b * b % mod;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll b, e, m;
	cin >> b >> e >> m;
	cout << pow(b, e, m) << '\n';
	return 0;
}
