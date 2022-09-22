#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, i, u, v, x, ans=0;
	cin >> N >> M;
	vector<ll> prohibition;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		u--; v--;
		x = (1<<u) | (1<<v);
		prohibition.push_back(x);
	}
	sort(prohibition.begin(), prohibition.end());
	prohibition.erase(unique(prohibition.begin(), prohibition.end()), prohibition.end());
	for (i=0;i<(1<<N);i++) {
		bool ok = true;
		for (ll &j : prohibition) {
			if ((i & j) == j) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
