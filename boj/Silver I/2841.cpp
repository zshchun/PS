#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, P, i, l, p, ans = 0;
	cin >> N >> P;
	set<int> a[7];
	for (i=0;i<N;i++) {
		cin >> l >> p;
		auto it = upper_bound(a[l].begin(), a[l].end(), p);
		while (it != a[l].end()) {
			a[l].erase(it);
			ans++;
			it = upper_bound(a[l].begin(), a[l].end(), p);
		}
		if (a[l].count(p) == 0) {
			ans++;
			a[l].insert(p);
		}
	}
	cout << ans << endl;

	return 0;
}
