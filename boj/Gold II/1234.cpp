#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, ans;
ll C[11][11];

void combination() {
	for (int i=0;i<11;i++) {
		C[i][0] = 1;
		for (int j=1;j<=i;j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
}


ll dfs(ll lv, ll r, ll g, ll b) {
	ll ret = 0;
	if (lv > n) {
		return 1;
	}
	if (lv <= r)
		ret += dfs(lv+1, r-lv, g, b);
	if (lv <= g)
		ret += dfs(lv+1, r, g-lv, b);
	if (lv <= b)
		ret += dfs(lv+1, r, g, b-lv);
	if (lv % 2 == 0 && r >= lv/2 && g >= lv/2)
		ret += C[lv][lv/2] * dfs(lv+1, r-lv/2, g-lv/2, b);
	if (lv % 2 == 0 && r >= lv/2 && b >= lv/2)
		ret += C[lv][lv/2] * dfs(lv+1, r-lv/2, g, b-lv/2);
	if (lv % 2 == 0 && g >= lv/2 && b >= lv/2)
		ret += C[lv][lv/2] * dfs(lv+1, r, g-lv/2, b-lv/2);
	if (lv % 3 == 0 && r >= lv/3 && g >= lv/3 && b >= lv/3)
		ret += C[lv][lv/3] * C[lv-lv/3][lv/3] * dfs(lv+1, r-lv/3, g-lv/3, b-lv/3);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll r, g, b;
	cin >> n >> r >> g >> b;

	combination();
	ans = dfs(1, r, g, b);
	cout << ans << endl;

	return 0;
}
