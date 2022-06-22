#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<pl> a;
		for (i=1;i<=n;i++) {
			cin >> x;
			if (x > 0) {
				ll d = max(1ll, i-x+1);
				a.push_back(pl(d, i));
			}
		}
		sort(a.begin(), a.end());
		vector<ll> b(n+1, 0);
		ll l = 0;
		for (i=0;i<a.size();i++) {
			ll d = a[i].first;
			ll u = a[i].second;
			if (u < l) continue;
			if (d < l) d = l;
			for (j=d;j<=u;j++) {
				b[j] = 1;
			}
			l = u;
		}

		for (i=1;i<=n;i++) {
			if (b[i])
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return 0;
}
