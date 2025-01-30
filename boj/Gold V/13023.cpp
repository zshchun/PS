#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans;
vector<int> g[2001];
bool visited[2001];

void dfs(int x, int streak) {
	if (ans || visited[x])
		return;
	visited[x] = 1;

	if (streak >= 4) {
		ans = 1;
		return;
	}

	for (int &next : g[x]) {
		dfs(next, streak+1);
	}
	visited[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int u, v, i;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (i=0;i<N;i++) {
		if (ans) break;
		dfs(i, 0);
	}

	cout << ans << endl;
	return 0;
}
