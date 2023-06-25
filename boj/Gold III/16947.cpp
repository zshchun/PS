#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"

int idx = 1;
int visited[3001];
int N;
int PREV[3001];
int d[3001];
bool cycle[3001];
vector<int> g[3001];
bool found = false;

void dfs(int cur) {
	visited[cur] = idx++;
	for (int next: g[cur]) {
		if (found) return;
		if (!visited[next]) {
			PREV[next] = cur;
			dfs(next);
		} else if (next != PREV[cur]) {
			cycle[cur] = 1;
			while (next != cur) {
				cur = PREV[cur];
				cycle[cur] = 1;
			}
			found = true;
		}
	}
}

void bfs() {
	queue<pa> q;
	for (int i=1;i<=N;i++) {
		if (cycle[i]) {
			visited[i] = 1;
			q.push(pa(i, 0));
		}
	}
	int cur, dist;
	while (!q.empty()) {
		tie(cur, dist) = q.front();
		q.pop();
		for (int next : g[cur]) {
			if (visited[next]) continue;
			visited[next] = 1;
			d[next] = dist + 1;
			q.push(pa(next, dist + 1));


		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int u, v, i;
	for (i=0;i<N;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	memset(visited, 0, sizeof(visited));

	bfs();

	for (i=1;i<=N;i++) {
		cout << d[i] << ' ';
	}
	cout << endl;

	return 0;
}
