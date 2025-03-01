#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, ans;
vector<int> g[500001];
bool visited[500001];

void dfs(int x, int d) {
	if (visited[x]) return;
	visited[x] = 1;

	if (g[x].size() == 1 && x != 1) {
		ans += d;
		return;
	}

	for (int &i : g[x])
		dfs(i, d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> n;
	for (i=0;i<n-1;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);

	if (ans & 1)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
