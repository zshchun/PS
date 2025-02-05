#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
vector<int> g[501];
int d[501];
int ind[501];
int ans[501];
int N, acc;

void topological_sort() {
	int i;
	queue<int> q;
	for (i=0;i<N;i++) {
		if (!ind[i]) {
			q.push(i);
			ans[i] = d[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int &next : g[cur]) {
			ind[next]--;
			ans[next] = max(ans[cur] + d[next], ans[next]);
			if (!ind[next])
				q.push(next);
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> d[i];
		while (1) {
			cin >> j;
			if (j == -1) break;
			j--;
			g[j].push_back(i);
			ind[i]++;
		}
	}

	topological_sort();

	for (i=0;i<N;i++)
		cout << ans[i] << endl;

	return 0;
}
