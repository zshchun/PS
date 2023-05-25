#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll N, M;
ll indegree[1001];
vector<ll> g[1001];
vector<ll> ans;

void topological_sort() {
	ll i;
	queue<ll> q;
	for (i=1;i<=N;i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		ll cur = q.front();
		q.pop();
		ans.push_back(cur);

		for (ll x : g[cur]) {
			indegree[x]--;
			if (indegree[x] == 0) {
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll i, j, k, u, v;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> k >> u;
		for (j=1;j<k;j++) {
			cin >> v;
			g[u].push_back(v);
			indegree[v]++;
			u = v;
		}
	}

	topological_sort();

	if (ans.size() != N) {
		cout << "0\n";
	} else {
		for (ll x : ans)
			cout << x << endl;
	}

	return 0;
}
