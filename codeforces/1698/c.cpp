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
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		vector<ll> a;
		set<ll> s;
		for (i=0;i<n;i++) {
			cin >> j;
			if (j) a.push_back(j);
			s.insert(j);
		}
		if (a.size() > 4) {
			cout << "NO\n";
			continue;
		}
		j = min(3ll, n - (ll)a.size());

		for (i=0;i<j;i++)
			a.push_back(0);

		bool ok = true;
		for (i=0;i<(ll)a.size();i++) {
			for (j=i+1;j<(ll)a.size();j++) {
				for (k=j+1;k<(ll)a.size();k++) {
					if (s.count(a[i] + a[j] + a[k]) == 0) {
						ok = false;
						break;
					}
				}
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
