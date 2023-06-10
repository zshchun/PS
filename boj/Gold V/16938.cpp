#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll n, l, r, x, ans;
ll a[15];

void dfs(ll cur, ll first, ll last, ll c) {
	if (cur == n) {
		if (c >= l && c <= r && first != -1 && last != -1 && a[first]+x <= a[last])
			ans++;
		return;
	}

	dfs(cur+1, first, last, c);
	dfs(cur+1, first == -1 ? cur : first, cur, c + a[cur]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	cin >> n >> l >> r >> x;

	for (i=0;i<n;i++)
		cin >> a[i];

	sort(a, a+n);

	dfs(0, -1, -1, 0);
	cout << ans << endl;

	return 0;
}
