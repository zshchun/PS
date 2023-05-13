#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 12345678
int visited[300001];
vector<int> g[300001];
vector<int> ans;
int N, M, K, X;
void bfs() {
	int cur;
	queue<int> q;
	q.push(X);
	visited[X] = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (visited[cur] > K)
			continue;
		else if (visited[cur] == K)
			ans.push_back(cur);
		for (int u : g[cur]) {
			if (visited[cur] + 1 < visited[u]) {
				q.push(u);
				visited[u] = visited[cur] + 1;
			}
		}
	}
}

int main() {
	int i, u, v;
	cin >> N >> M >> K >> X;
	fill(visited, visited+300001, INF);
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	bfs();
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	if (ans.size() == 0)
		cout << "-1\n";
	else
		for (int x : ans)
			cout << x << endl;
	return 0;
}
