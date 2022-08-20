#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ull n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ull T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ull b, s;
		cin >> n >> k >> b >> s;
		l = k*b;
		r = l + n*(k-1);
		if (s >= l && s <= r) {
			j = s - l;
			for (i=0;i<n-1;i++) {
				if (j> k-1) {
					cout << k-1 << ' ';
					j -= k-1;
				} else {
					cout << 0 << ' ';
				}
			}
			cout << (k*b)+j << endl;
		} else {
			cout << "-1\n";
			continue;
		}
	}
	return 0;
}
