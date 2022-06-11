#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, m;
	int a[10000] = { 0, };
	int dp[10000] = { 0, };
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	
	dp[0] = a[0];
	if (n >= 1)
		dp[1] = a[0] + a[1];
	if (n >= 2)
		dp[2] = max(a[2] + max(dp[0], a[1]), dp[1]);
	for(i=3;i<n;i++)
		dp[i] = max(a[i] + max(dp[i-2], dp[i-3]+a[i-1]), dp[i-1]);
	for(m=0,i=0;i<n;i++)
		m = max(dp[i], m);
	cout << m << "\n";
	return 0;
}
