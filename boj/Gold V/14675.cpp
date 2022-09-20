#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, Q, i, k, u, v, x, y, q;
	cin >> N;
	vector<ll> tree(N+1);
	for (i=0;i<N-1;i++) {
		cin >> u >> v;
		tree[u]++;
		tree[v]++;
	}

	cin >> Q;
	bool ok;
	for (i=0;i<Q;i++) {
		cin >> q >> k;
		if (q == 1) {
			if (tree[k] >= 2)
				ok = true;
			else
				ok = false;
		} else if (q == 2) {
			ok = true;
		}
		if (ok)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
