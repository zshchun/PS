#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
int N, M;
vector<pa> g[101];
int dp[101][101];
int ind[101];
vector<int> basic;

void topological_sort() {
	int i;
	queue<int> q;
	for (i=1;i<=N;i++)
		if (ind[i] == 0) {
			basic.push_back(i);
			q.push(i);
			dp[i][i] = 1;
		}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto &[next, cost] : g[cur]) {
			for (i=1;i<N;i++)
				dp[next][i] += dp[cur][i] * cost;
			if (--ind[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, u, v, c;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> v >> u >> c;
		g[u].push_back(pa(v, c));
		ind[v]++;
	}

	topological_sort();

	for (int i : basic)
		cout << i << " " << dp[N][i] << endl;
	return 0;
}
