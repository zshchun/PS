#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int n, m, s, t, ans = 0;
vector<pa> g[5001];
int visited[5001];

void bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (pa &n : g[cur]) {
			int to = n.first;
			int weight = n.second;
			if (visited[to] > visited[cur] + weight) {
				visited[to] = visited[cur] + weight;
				q.push(to);
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b, c;
	cin >> n >> m;
	for (i=1;i<=n;i++)
		visited[i] = INF;

	for (i=0;i<m;i++) {
		cin >> a >> b >> c;
		g[a].push_back(pa(b, c));
		g[b].push_back(pa(a, c));
	}

	cin >> s >> t;

	bfs();
	
	cout << visited[t] << endl;

	return 0;
}
