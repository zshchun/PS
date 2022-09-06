#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll idx, n, ans = -1;
ll a[11];
void dfs(ll digit, ll cur, ll lastnum) {
	ll i;
	if (digit == cur) {
		idx++;
		if (idx == n) {
			ans = 0;
			for (i=0;i<digit;i++)
				ans = ans * 10 + a[i];
		}
		return;
	}
	if (lastnum == 0) return;
	for (i=0;i<lastnum;i++) {
		a[cur] = i;
		dfs(digit, cur+1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> n;
	for (i=1;i<=10;i++)
		dfs(i, 0, 10);
	cout << ans << endl;
	return 0;
}
