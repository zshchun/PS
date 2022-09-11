#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007

ll xgcd(int a, int b) {
	ll q, r, s, r1=a, r2=b, s1=1, s2=0;
	while (r2) {
		q = r1 / r2;
		r = r1 - r2 * q;
		r1 = r2;
		r2 = r;
		s = s1 - s2 * q;
		s1 = s2;
		s2 = s;
	}
	if (s1 < 0) s1 += b;
	return s1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, N, S, i;
	ll ans = 0;
	cin >> M;
	for (i=0;i<M;i++) {
		cin >> N >> S;
		ans = ans + (S * xgcd(N, MOD) % MOD);
		if (ans >= MOD) ans -= MOD;
	}
	cout << ans << '\n';
	return 0;
}
