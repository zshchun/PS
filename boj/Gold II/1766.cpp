#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;
vector<int> g[32001];
int indgree[32001];

void topological_sort() {
	priority_queue<int, vector<int>, greater<int>> q;
	int i;
	for (i=1;i<=N;i++) {
		if (indgree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cout << cur << ' ';
		for (int next : g[cur]) {
			indgree[next]--;
			if (indgree[next] == 0) {
				q.push(next);
			}
		}
	}
	cout << endl;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int i, u, v;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		indgree[v]++;
	}

	topological_sort();

	return 0;
}
