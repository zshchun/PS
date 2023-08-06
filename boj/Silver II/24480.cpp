#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
vector<int> g[100001];
bool visited[100001];
int order[100001];
int N, M, R, idx = 1;

void dfs(int s) {
	visited[s] = 1;
	order[s] = idx;
	idx++;
	for (int x : g[s]) {
		if (!visited[x])
			dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	int i, u, v;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (i=1;i<=N;i++)
		sort(g[i].begin(), g[i].end(), greater<int>());

	dfs(R);
	for (i=1;i<=N;i++) {
		cout << order[i] << endl;
	}

	return 0;
}
