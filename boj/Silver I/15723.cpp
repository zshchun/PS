#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

vector<int> g[27];
int visited[27];

int dfs(int u, int v) {
	if (u == v) return 1;
	if (visited[u]) return 0;
	visited[u] = 1;
	if (g[u].size() != 1) return 0;
	
	return dfs(g[u].back(), v);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string x;
	char u, v;
	int n, m, i;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> u >> x >> v;
		u -= 'a'; v -= 'a';
		g[u].push_back(v);
	}

	cin >> m;
	for (i=0;i<m;i++) {
		memset(visited, 0, sizeof(visited));
		cin >> u >> x >> v;
		u -= 'a'; v -= 'a';
		if (dfs(u, v))
			cout << "T\n";
		 else 
			cout << "F\n";
	}

	return 0;
}
