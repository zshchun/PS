#include <bits/stdc++.h>
using namespace std;
int s[300], dp[300];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	for (i=0;i<n;i++)
		cin >>s[i];
	
	dp[0] = s[0];
	dp[1] = s[0] + s[1];
	dp[2] = max(s[0], s[1]) + s[2];
	for (i=3;i<n;i++) {
		dp[i] = max(dp[i-2]+s[i], dp[i-3]+s[i-1]+s[i]);
	}
	cout << dp[n-1] << '\n';
	return 0;
}
