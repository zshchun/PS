#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int K, ans;
int a[2<<20+1];

int dfs(int s, int lv) {
	if (lv >= K) return a[s];
	int l, r, d;
	l = dfs(s*2, lv+1);
	r = dfs(s*2+1, lv+1);
	d = abs(l-r);
	if (l < r) a[s*2] += d;
	else a[s*2+1] += d;
	return max(l, r) + a[s];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> K;
	i = 2;
	while (cin >> v)
		a[i++] = v;
	dfs(1, 0);
	ans = accumulate(a+2, a+(2<<K), 0);
	cout << ans << endl;
	
	return 0;
}
