#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, R;
vector<int> g[100001];
int visited[100001];
int idx = 2;

void bfs() {
	queue<int> q;
	q.push(R);
	visited[R] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : g[cur]) {
			if (visited[next])
				continue;
			visited[next] = idx++;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N >> M >> R;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (i=1;i<=N;i++)
		sort(g[i].begin(), g[i].end());
	bfs();

	for (i=1;i<=N;i++)
		cout << visited[i] << endl;

	return 0;
}
