#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int A, B, N, M, ans;
vector<int> g[1001];
int visited[1001];

void bfs() {
	queue<int> q;
	q.push(A);
	visited[A] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == B)
			break;
		for (int next : g[cur]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = visited[cur] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> A >> B;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	bfs();
	cout << visited[B] - 1 << endl;
	return 0;
}
