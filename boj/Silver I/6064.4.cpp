#include <bits/stdc++.h>
using namespace std;
tuple<int,int,int> xgcd(int a, int b) {
	int s1=1, s2=0, t1=0, t2=1, s, t, r, q;
	while (b) {
		q = a / b;
		r = a % b;
		a = b;
		b = r;

		s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	return make_tuple(a, s1, t1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, N1, N2, n1, n2, a1, a2, N, M1, M2, s, G;
	cin >> t;
	while (t--) {
		cin >> n1 >> n2 >> a1 >> a2;

		s = 0;
		N = n1 * n2;

		N1 = N / n1;
		tie(G, M1, ignore) = xgcd(N1, n1);
		if (M1 < 0) M1 = M1 % n1 + n1;
		s += a1 * M1 * N1 / G;

		N2 = N / n2;
		tie(G, M2, ignore) = xgcd(N2, n2);
		if (M2 < 0) M2 = M2 % n2 + n2;
		s += a2 * M2 * N2 / G;

		s %= N;
		cout << s << '\n';

	}
	return 0;
}
