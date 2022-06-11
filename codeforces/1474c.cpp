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
		multiset<ll,greater<ll>> c;
		vector<pl> b;
		ans = 0;
		for (i=0;i<n*2;i++) {
			cin >> x;
			c.insert(x);
		}
		bool ok = false;
		ll l;
		multiset<ll,greater<ll>>::iterator it;
		it = c.begin();
		it++;
		for (auto it2=it;it2!=c.end();it2++) {
			b.clear();
			multiset<ll,greater<ll>> a(c.begin(), c.end());
			it = a.begin();
			l = *it;
			a.erase(it);
			b.push_back(pl(*it2, l));
			a.erase(a.find(*it2));

			while (!a.empty()) {
				it = a.begin(); ll k = *it; a.erase(it);
				if (a.count(l-k) == 0) break;
				a.erase(a.find(l-k));
				b.push_back(pl(l-k, k));
				l = k;

			}
			if (a.empty()) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << b[0].first + b[0].second << endl;
			for (pl &p : b) {
				cout << p.first << " " << p.second << endl;
			}
		}
	}
	return 0;
}
