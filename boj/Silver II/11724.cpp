#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
vector<int> m[1001];
int N, M;
void dfs(int x) {
	for (int i : m[x]) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, ans=0;
	cin >> N >> M;
	for (i=1;i<=M;i++) {
		cin >> u >> v;
		m[u].push_back(v);
		m[v].push_back(u);
	}
	for (i=1;i<=N;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
