#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
vector<int> g[100001];
int order[100001];
int N, M, R, idx = 1;

void dfs(int x) {
	if (order[x])
		return;
	order[x] = idx;
	idx++;
	for (int y : g[x]) {
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N >> M >> R;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (i=0;i<N;i++)
		sort(g[i].begin(), g[i].end());

	dfs(R - 1);

	for (i=0;i<N;i++) {
		cout << order[i] << endl;
	}
	return 0;
}
