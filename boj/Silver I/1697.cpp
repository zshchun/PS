#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, i;
	queue<int> q;
	cin>>n>>k;
	int *dp = new int[200002]();
	q.push(n);
	dp[n] = 1;
	while (!q.empty()) {
		i = q.front();
		q.pop();
		if (i == k) {
			cout << dp[i]-1 << "\n";
			return 0;
		}
		if (i > 0 && !dp[i-1]) {
			q.push(i-1);
			dp[i-1] = dp[i] + 1;
		}
		if (i < k && !dp[i+1]) {
			q.push(i+1);
			dp[i+1] = dp[i] + 1;
		}
		if (i < k && !dp[i*2]) {
			q.push(i*2);
			dp[i*2] = dp[i] + 1;
		}
	}
	return 0;
}
