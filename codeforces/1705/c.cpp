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
	ll TC, i, j, k, l, r, c, q, sz, pos;
	cin >> TC;
	while(TC--) {
		cin >> n >> c >> q;
		string s;
		cin >> s;
		pos = n;
		vector<pa> a;
		a.push_back(pa(0, 0));
		for (i=0;i<c;i++) {
			cin >> j >> k;
			j--;
			a.push_back(pa(pos, j));
			pos += k - j;
		}
		a.push_back(pa(pos, pos));
		sort(a.begin(), a.end());
		for (i=0;i<q;i++) {
			cin >> j;
			j--;
			while (j >= s.size()) {
				l = 0;
				r = a.size()-1;
				while (r-l > 1) {
					m = (r + l) >> 1;
					if (j >= a[m].first)
						l = m;
					else if (j < a[m].first)
						r = m;
				}
				j = a[l].second + (j - a[l].first);
			}
			cout << s[j] << endl;
		}
	}
	return 0;
}
