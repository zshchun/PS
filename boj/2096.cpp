#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a[100001][3];
int max_dp[3];
int max_prev[3];
int min_dp[3];
int min_prev[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		max_dp[0] = max(max_prev[0], max_prev[1]) + a[i][0];
		max_dp[1] = max(max(max_prev[0], max_prev[1]), max_prev[2]) + a[i][1];
		max_dp[2] = max(max_prev[1], max_prev[2]) + a[i][2];

		min_dp[0] = min(min_prev[0], min_prev[1]) + a[i][0];
		min_dp[1] = min(min(min_prev[0], min_prev[1]), min_prev[2]) + a[i][1];
		min_dp[2] = min(min_prev[1], min_prev[2]) + a[i][2];
		memcpy(max_prev, max_dp, sizeof(max_dp));
		memcpy(min_prev, min_dp, sizeof(min_dp));
	}
	int ans1 = max(max(max_dp[0], max_dp[1]), max_dp[2]);
	int ans2 = min(min(min_dp[0], min_dp[1]), min_dp[2]);
	cout << ans1 << " " << ans2 << '\n';
	return 0;
}
