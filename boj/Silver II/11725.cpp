#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N;
vector<int> g[100001];
int visited[100001];
void dfs(int s) {
	int i;
	for (i=0;i<g[s].size();i++) {
		int x = g[s][i];
		if (visited[x]) continue;
		visited[x] = s;
		dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N;
	for (i=1;i<N;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for (int i=2;i<=N;i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}

