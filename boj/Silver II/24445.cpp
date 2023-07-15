#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, R, order, ans;
int visited[100001];
vector<int> g[100001];

void bfs() {
	int cur;
	queue<int> q;
	q.push(R);
	visited[R] = order;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int next : g[cur]) {
			if (visited[next])
				continue;
			order++;
			visited[next] = order;
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
	order = 1;
	for (i=1;i<=N;i++)
		sort(g[i].begin(), g[i].end(), greater<int>());

	bfs();

	for (i=1;i<=N;i++)
		cout << visited[i] << endl;

	return 0;
}
