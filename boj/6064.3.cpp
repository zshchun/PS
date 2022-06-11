#include <bits/stdc++.h>
using namespace std;
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
	if (t1 < 0) t1 = t1 % b + b;
	if (s1 < 0) s1 = s1 % b + b;
	return make_tuple(r1, s1, t1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2, a1, a2, s, N1, N2, G, M1, M2, T, N, v;
	cin >> T;
	while (T--) {
		cin >> n1 >> n2 >> a1 >> a2;
		N = n1 * n2;
		if (a1 == n1 && a2 == n2) {
			tie(G, ignore, ignore) = xgcd(n1, n2);
			int lcm = n1 * n2 / G;
			cout << lcm << '\n';
			continue;
		} else if (a1 == n1) a1 = 0;
		else if (a2 == n2) a2 = 0;

		s = 0;
		N1 = N / n1;
		tie(G, M1, ignore) = xgcd(N1, n1);
		v = a1 * N1 * M1;
		cout << v << '\n';
		if (v % n1 != a1) {
			cout << "-1\n";
			continue;
		}
		s += v;

		N2 = N / n2;
		tie(G, M2, ignore) = xgcd(N2, n2);
		v = a2 * N2 * M2;
		cout << v << '\n';
		if (v % n2 != a2) {
			cout << "-1\n";
			continue;
		}
		s += v;
		s = s % N;
		cout << s << '\n';
	}
	return 0;
}
