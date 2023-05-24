#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, L, i, s, e;
	cin >> N >> L;
	ll next = 0;
	ll ans = 0;
	vector<pa> a;

	for (i=0;i<N;i++) {
		cin >> s >> e;
		a.push_back(pa(s, e));
	}

	sort(a.begin(), a.end());

	for (pa &p : a) {
		if (p.first > next) {
			next = p.first;
		}
		ll x = ((p.second - next) + (L-1)) / L;
		next = next + (L * x);
		ans += x;
	}


	cout << ans << endl;
	return 0;
}
