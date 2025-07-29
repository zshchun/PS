#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789123ULL

vector<pa> g[5001];
ll dist[5001];
bool used[5001];
ll n, ans;

void dfs(ll cur, ll x) {
	if (used[cur]) return;
	used[cur] = 1;
	ans = max(ans, x);

	for (auto [next, d] : g[cur]) {
		if (dist[next] < x + d) {
			dist[next] = x + d;
			dfs(next, dist[next]);
		}
	}
	used[cur] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll u, v, d, i;
	cin >> n;
	for (i=0;i<n-1;i++) {
		cin >> u >> v >> d;
		g[u].push_back(pa(v, d));
		g[v].push_back(pa(u, d));
	}
	dfs(1, 0);
	cout << ans << endl;

	return 0;
}
