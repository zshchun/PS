#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, ans;
int a[5000];
int dp[5000][5000];

int dfs(int l, int r) {
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	if (l >= r) {
		return 0;
	}

	if (a[l] == a[r]) {
		dp[l][r] = dfs(l+1, r-1);
	} else {
		dp[l][r] = min(dfs(l, r-1), dfs(l+1, r))+1;
	}
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N;

	for (i=0;i<N;i++)
		cin >> a[i];

	fill(&dp[0][0], &dp[0][0]+5000*5000, -1);

	ans = dfs(0, N-1);
	cout << ans << endl;

	return 0;
}
