#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int d[100001];
int visited[100001];
int N, K, W, ans;
int indgree[100001];
vector<int> g[100001];

void topological_sort() {
	queue<int> q;
	int i;
	for (i=1;i<=N;i++)
		if (indgree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int x : g[cur]) {
			visited[x] = max(visited[x], visited[cur] + d[cur]);
			indgree[x]--;
			if (indgree[x] == 0) {
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, u, v;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		ans = 0;
		for (i=1;i<=N;i++) {
			cin >> d[i];
			g[i].clear();
			indgree[i] = 0;
			visited[i] = 0;
		}
		for (i=0;i<K;i++) {
			cin >> u >> v;
			g[u].push_back(v);
			indgree[v]++;
		}
		cin >> W;
		// topological sort
		topological_sort();
		cout << visited[W] + d[W] << endl;
	}
	return 0;
}
