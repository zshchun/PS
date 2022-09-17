#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k, c, q, l, r;
	cin >> TC;
	while(TC--) {
		cin >> n >> c >> q;
		string s;
		cin >> s;
		vector<ll> pos, sz;
		pos.push_back(0);
		sz.push_back(n);
		for (i=0;i<c;i++) {
			cin >> l >> r;
			l--;
			pos.push_back(l);
			sz.push_back(sz.back()+r-l);
		}
		while (q--) {
			cin >> k;
			k--;
			for (i=c;i>0;i--)
				if (k >= sz[i-1])
					k = pos[i] + (k - sz[i-1]);
			cout << s[k] << endl;
		}
	}
	return 0;
}
