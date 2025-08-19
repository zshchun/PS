#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n;
vector<int> dp[51];
vector<int> a[51];

int dfs(int cur) {
	for (int &next : a[cur])
		dp[cur].push_back(dfs(next));
	sort(dp[cur].begin(), dp[cur].end(), greater<int>());
	int ret = 0;
	for (int i=0;i<dp[cur].size();i++)
		ret = max(ret, dp[cur][i] + i + 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v >= 0) a[v].push_back(i);
	}
	
	cout << dfs(0) << endl;
	return 0;
}
