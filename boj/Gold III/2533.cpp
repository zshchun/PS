#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
vector<int> g[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int cur) {
	visited[cur] = 1;
	dp[cur][1] = 1;
	for (int &next : g[cur]) {
		if (visited[next]) continue;
		dfs(next);
		dp[cur][0] += dp[next][1];
		dp[cur][1] += min(dp[next][0], dp[next][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N;
	for (i=0;i<N-1;i++) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);
	ans = min(dp[0][0], dp[0][1]);
	cout << ans << endl;

	return 0;
}
