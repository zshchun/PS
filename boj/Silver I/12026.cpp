#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, ans = INF;
vector<int> boj[3];
int dp[1001];

int dfs(int idx, int last) {
	if (last == N) {
		return 0;
	}
	if (dp[last])
		return dp[last];

	int next = (idx + 1) % 3;

	int m = INF;
	auto it = upper_bound(boj[next].begin(), boj[next].end(), last);
	for ( ;it != boj[next].end(); it++) {
		int x = *it;
		int d = x - last;
		m = min(m, dfs(next, x) + d * d);
	}
	dp[last] = m;
	return dp[last];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	char c;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> c;
		if (c == 'B')
			boj[0].push_back(i);
		else if (c == 'O')
			boj[1].push_back(i);
		else if (c == 'J')
			boj[2].push_back(i);
	}

	ans = dfs(0, 1);

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
