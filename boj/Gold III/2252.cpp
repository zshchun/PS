#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;
vector<int> g[32001];
int ind[32001];

void topological_sort() {
	int i;
	queue<int> q;
	for (i=1;i<=N;i++) {
		if (!ind[i]) {
			q.push(i);
			cout << i << ' ';
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : g[cur]) {
			ind[next]--;
			if (!ind[next]) {
				q.push(next);
				cout << next << ' ';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		ind[v]++;
	}
	topological_sort();

	return 0;
}
