#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, R;
int visited[100001];
vector<int> a[100001];

void bfs() {
	queue<int> q;
	q.push(R);
	visited[R] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int &next : a[cur]) {
			if (visited[next] != -1)
				continue;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N >> M >> R;
	for (i=1;i<=M;i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	fill_n(visited, N+1, -1);

	bfs();

	for (i=1;i<=N;i++)
		cout << visited[i] << endl;

	return 0;
}
