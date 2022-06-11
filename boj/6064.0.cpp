#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

tuple<int,int,int> xgcd(int a, int b) {
	int q, r, s, t, r1=a, r2=b, s1=1, s2=0, t1=0, t2=1;
	while (r2) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	return make_tuple(r1, s1, t1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n1, n2, a1, a2, s, G, M1, M2, T, N;
	cin >> T;
	while (T--) {
		cin >> n1 >> n2 >> a1 >> a2;

		if (a1 == n1 && a2 == n2) {
			int lcm = n1 * n2 / gcd(n1, n2);
			cout << lcm << '\n';
			continue;
		}
		if (a1 == n1) a1 = 0;
		if (a2 == n2) a2 = 0;

		G = gcd(n1, n2);
		if (a1 % G != a2 % G) {
			cout << "-1\n";
			continue;
		}
		N = n1 / G * n2;
		s = 0;
		tie(ignore, M1, M2) = xgcd(n1/G, n2/G);
		s += a1 * (n2/ G) % N*M2 % N;
		s += a2 * (n1/G) % N*M1 % N;
		s = s % N;
		if (s < 0) s += N;
		cout << s << '\n';
	}
	return 0;
}
