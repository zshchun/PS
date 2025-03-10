#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int k, m, p, T, ans;
int ind[1001];
int strahler[1001];
int cnt[1001];

void topological_sort(vector<int> (&g)[]) {
	queue<int> q;
	int i;
	for (i=0;i<m;i++) {
		if (ind[i] == 0) {
			q.push(i);
			strahler[i] = 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int &x: g[cur]) {
			if (strahler[cur] > strahler[x]) {
				strahler[x] = strahler[cur];
				cnt[x] = 1;
			} else if (strahler[cur] == strahler[x]) {
				cnt[x]++;
			}
			ind[x]--;
			if (ind[x] == 0) {
				if (cnt[x] >= 2)
					strahler[x]++;
				ans = max(ans, strahler[x]);
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int u, v, i;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> k >> m >> p;
		memset(ind, 0, sizeof(ind));
		memset(strahler, 0, sizeof(strahler));
		memset(cnt, 0, sizeof(cnt));
		vector<int> g[m+1];

		for (i=0;i<p;i++) {
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			ind[v]++;
		}
		topological_sort(g);
		cout << k << ' ' << ans << endl;
	}
	return 0;
}
