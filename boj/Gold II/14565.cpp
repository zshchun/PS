#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

// Extended Euclidean
ll xgcd(ll a, ll b) {
	ll q, r, s, t, r1 = a, r2 = b;
	ll s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	while (1) {
		q = r1 / r2;
		r = r1 - q * r2;
		if (r == 0) return s2;
		r1 = r2;
		r2 = r;

		s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, a, b;
	cin >> n >> a;
	if (gcd(a, n) != 1)
		b = -1;
	else
		b = (xgcd(a, n) + n) % n;

	cout << n - a << ' ' << b << endl;

	return 0;
}
