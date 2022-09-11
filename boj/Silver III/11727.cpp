#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (i=3;i<=N;i++) {
		dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
	}
	cout << dp[N] << '\n';
	return 0;
}

