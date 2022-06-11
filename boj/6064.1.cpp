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
	if (s1 < 0) s1 = s1 % b + b;
	if (t1 < 0) t1 = t1 % b + b;
	return make_tuple(r1, s1, t1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, G, N, n1, n2, N1, N2, a1, a2, M1, M2, s;
	cin >> T;
	while (T--) {
		cin >> n1 >> n2 >> a1 >> a2;
		N = n1 * n2;
		N1 = N / n1;
		N2 = N / n2;

		s = 0;
		tie(G, M1, ignore) = xgcd(N1, n1);
		s += (a1 * M1 * N1) / G;
		tie(G, M2, ignore) = xgcd(N2, n2);
		s += (a2 * M2 * N2) / G;
		s = s % N;
		if (s % n1 != a1 || s % n2 != a2)
			cout << "-1\n";
		else
			cout << s << '\n';

	}
	return 0;
}
