#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
ll ans = 30;
unordered_map<ll,ll> visited;

ll abc(ll a, ll b, ll c) {
	return (c << 40) | (b << 20) | a;
}

bool is_visited(ll v, ll cnt) {
	if (visited.find(v) != visited.end() && visited[v] <= cnt)
		return true;
	visited[v] = cnt;
	return false;
}

bool check(ll a, ll b, ll c) {
	while (a) {
		if ((a & 3) != 1)
			return false;
		a >>= 2;
	}
	while (b) {
		if ((b & 3) != 2)
			return false;
		b >>= 2;
	}
	while (c) {
		if ((c & 3) != 3)
			return false;
		c >>= 2;
	}
	return true;
}

void dfs(ll v, ll cnt) {
	ll c = (v >> 40) & 0xfffff;
	ll b = (v >> 20) & 0xfffff;
	ll a = v & 0xfffff;
	ll nv;
	if (ans < cnt || is_visited(v, cnt))
		return;

	if (check(a, b, c))
		ans = min(ans, cnt);

	if (a) {
		nv = abc(a >> 2, (b << 2) | (a & 3), c);
		dfs(nv, cnt+1);
		nv = abc(a >> 2, b, (c << 2) | (a & 3));
		dfs(nv, cnt+1);
	}
	if (b) {
		nv = abc((a << 2) | (b & 3), b >> 2, c);
		dfs(nv, cnt+1);
		nv = abc(a, b >> 2, (c << 2) | (b & 3));
		dfs(nv, cnt+1);
	}
	if (c) {
		nv = abc((a << 2) | (c & 3), b, c >> 2);
		dfs(nv, cnt+1);
		nv = abc(a, (b << 2) | (c & 3), c >> 2);
		dfs(nv, cnt+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, n, v[3] = {0, };
	char ch;
	for (i=0;i<3;i++) {
		cin >> n;
		for (j=0;j<n;j++) {
			cin >> ch;
			if (ch == 'A')
				v[i] = (v[i] << 2) | 1ull;
			else if (ch == 'B')
				v[i] = (v[i] << 2) | 2ull;
			else if (ch == 'C')
				v[i] = (v[i] << 2) | 3ull;
		}
	}
	dfs(abc(v[0], v[1], v[2]), 0);
	cout << ans << endl;
	return 0;
}
