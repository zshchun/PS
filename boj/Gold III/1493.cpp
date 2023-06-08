#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll L, W, H, N, cur, ans;
bool found = true;

ll cube[21];

void dfs(ll l, ll w, ll h) {
	if (!l || !w || !h)
		return;
	for (ll i=N-1; i >= 0; i--) {
		if (!cube[i]) continue;
		ll x = 1 << i;
		if (l < x || w < x || h < x)
			continue;
		ans++;
		cube[i]--;
		dfs(l-x, w, h);
		dfs(x, w-x, h);
		dfs(x, x, h-x);
		return;
	}
	found = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> L >> W >> H;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> j >> k;
		cube[j] = k;
	}

	dfs(L, W, H);

	if (found)
		cout << ans << endl;
	else
		cout << "-1\n";

	return 0;
}
