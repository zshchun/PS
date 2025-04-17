#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, ans;
int d[10001];
int ind[10001];
int visited[10001];
vector<int> a[10001];

void topological_sort() {
	int cur, dist;
	queue<int> q;
	for (int i=0;i<N;i++)
		if (ind[i] == 0) {
			q.push(i);
			visited[i] = d[i];
		}

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int &next : a[cur]) {
			visited[next] = max(visited[next], visited[cur] + d[next]);
			if (--ind[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, m, u;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> d[i] >> ind[i];
		for (j=0;j<ind[i];j++) {
			cin >> u; u--;
			a[u].push_back(i);
		}
	}

	topological_sort();

	for (i=0;i<N;i++)
		ans = max(ans, visited[i]);

	cout << ans << endl;
	return 0;
}
