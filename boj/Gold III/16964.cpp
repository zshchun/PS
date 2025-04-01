#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N;
unordered_set<int> g[100001];
bool visited[100001];
int cur = 1;
int ans[100001];
int cnt;

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	bool found;

	do {
		int y = ans[cur];
		found = false;
		if (!visited[y] && g[x].find(y) != g[x].end()) {
			cur++;
			dfs(y);
			found = true;
		}
	} while (found);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N;
	for (i=1;i<N;i++) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	for (i=1;i<=N;i++)
		cin >> ans[i];

	if (ans[1] == 1) {
		cur++;
	} else {
		cout << "0\n";
		return 0;
	}

	dfs(1);

	for (i=1;i<=N;i++)
		cnt += visited[i];

	if (cnt != N)
		cout << "0\n";
	else
		cout << "1\n";

	return 0;
}
