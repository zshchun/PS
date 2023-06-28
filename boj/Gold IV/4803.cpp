#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll n, m;
bool is_tree;
bool visited[501];
vector<ll> g[501];

void dfs(ll x, ll prev) {
	if (!is_tree) return;
	if (visited[x]) {
		is_tree = false;
		return;
	}
	visited[x] = true;
	for (ll y : g[x]) {
		if (y == prev)
			continue;
		dfs(y, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, u, v, ans, idx = 1;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (i=1;i<=n;i++)
			g[i].clear();

		for (i=0;i<m;i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		ans = 0;
		memset(visited, 0, sizeof(visited));

		for (i=1;i<=n;i++) {
			if (visited[i]) continue;
			is_tree = true;
			dfs(i, 0);
			if (is_tree) {
				ans++;
			}
		}

		cout << "Case " << idx << ": ";
		if (ans > 1) {
			cout << "A forest of " << ans << " trees.\n";
		} else if (ans == 1) {
			cout << "There is one tree.\n";
		} else {
			cout << "No trees.\n";
		}
		idx++;
	}
	return 0;
}
