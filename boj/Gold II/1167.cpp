#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[100001];
vector<pair<int,int>> g[100001];
int node, dist;

void dfs(int n, int w) {
	int i, idx, d;
	if (visited[n]) return;
	visited[n] = 1;
	if (dist < w) {
		node = n;
		dist = w;
	}
	for (i=0;i<(int)g[n].size();i++) {
		tie(idx, d) = g[n][i];
		dfs(idx, w+d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, n, x, y, i;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> n;
		while (1) {
			cin >> x;
			if (x == -1) break;
			cin >> y;
			g[n].emplace_back(make_pair(x, y));
		}
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(bool)*(N+1));
	dfs(node, 0);
	cout << dist << '\n';
	
	return 0;
}

