#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, m, g;
	cin>>n;
	int *dp = new int[n+1]();
	int *a = new int[n+1]();
	for (i=1;i<=n;i++)
		cin >> a[i];
	for (g=0,i=1;i<=n;i++) {
		for (m=0,j=1;j<i;j++) {
			if (a[j] >= a[i])
				continue;
			if (dp[j] > m) {
				m = dp[j];
			}
		}
		dp[i] = m + 1;
		g = max(dp[i], g);
	}
	cout << g << "\n";
	return 0;
}
