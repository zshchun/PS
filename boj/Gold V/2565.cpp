#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
vector<pa> a;
int dp[501][501];

int dfs(int n, int last) {
	int ret = 0;
	if (n >= N)
		return 0;
	if (dp[n][last] != -1)
		return dp[n][last];
	int cur = a[n].second;
	if (last < cur)
		ret = max(ret, dfs(n+1, max(last, a[n].second))+1);
	ret = max(ret, dfs(n+1, last));
	dp[n][last] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N;
	fill_n(&dp[0][0], 501*501, -1);
	for (i=0;i<N;i++) {
		cin >> u >> v;
		a.push_back(pa(u, v));
	}
	sort(a.begin(), a.end());
	ans = dfs(0, 0);

	cout << N - ans << endl;

	return 0;
}
