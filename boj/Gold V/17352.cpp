#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
vector<ll> visited;
void dfs(vector<ll> *a, ll cur) {
	ll i, next;
	visited[cur] = 1;
	for (i=0;i<(ll)a[cur].size();i++) {
		next = a[cur][i];
		if (!visited[next])
			dfs(a, next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, u, v;
	cin >> n;
	vector<ll> a[n];
	visited.resize(n, 0ll);
	for (i=0;i<n-2;i++) {
		cin >> u >> v;
		u--; v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(a, 0);
	for (i=1;i<n;i++) {
		if (!visited[i]) {
			cout << "1 " << i+1 << endl;
			break;
		}
	}
	return 0;
}
