#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ll q, mq=0, mx=0, last=0;
		cin >> n >> q;
		vector<pa> a(n);
		vector<ll> v(n+1);
		for (i=0;i<n;i++) {
			cin >> a[i].first;
			a[i].second = i;
			if (mx < a[i].first) {
				mx = a[i].first;
				last = i;
			}
		}
		vector<ll> ans(q);
		vector<pair<ll,pa>> qs(q);
		for (i=0;i<q;i++) {
			cin >> qs[i].second.first >> qs[i].first;
			qs[i].first--;
			qs[i].second.first--;
			qs[i].second.second = i;
		}
		sort(qs.begin(), qs.end());
		j = 0;
		k = 0;
		for (i=1;i<=last;i++) {
			if (a[k].first < a[i].first) {
				k = i;
			}
			v[a[k].second]++;
			while (j < qs.size() && qs[j].first == i-1) {
				ans[qs[j].second.second] = v[qs[j].second.first];
				j++;
			}
		}

		for (;j<qs.size();j++) {
			ans[qs[j].second.second] = v[qs[j].second.first];
			if (qs[j].second.first == last && qs[j].first >= last) {
				ans[qs[j].second.second] += (qs[j].first-last+1);
			}
		}
		for (i=0;i<q;i++)
			cout << ans[i] << endl;
	}
	return 0;
}
