#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

ll pow(ll base, ll exp, ll mod) {
	ll b = base;
	ll e = exp;
	ll r = 1;
	while (e) {
		if (e&1) r = r * b % mod;
		e >>= 1;
		b = b * b % mod;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c) << '\n';
	return 0;
}

