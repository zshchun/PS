#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;
bool ok;

vector<ll> a[200001];
ll visited[200001];
void dfs(ll v, ll c, ll t) {
	if (!ok) return;
	if (visited[t] && v == t) {
		if (c %2) ok = false;
		return;
	}
	if (visited[v]) return;
	visited[v] = 1;
	for (int x : a[v]) {
		dfs(x, c+1, t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, q, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ll u, v;
		ans = 0;
		for (i=1;i<=n;i++) {
			a[i].clear();
			visited[i] = 0;
		}
		for (i=0;i<n;i++) {
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ok = true;

		for (i=1;i<=n;i++) {
			if (a[i].size() != 2) {
				ok = false;
				break;
			}
			dfs(i, 0, i);
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
