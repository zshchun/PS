#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int dp[1000001];
int main() {
	int N, i;
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (i=3;i<=N;i++) {
		if (i % 2)
			dp[i] = dp[i-1];
		else
			dp[i] = (dp[i-1] + dp[i/2]) % 1000000000;
	}
	cout << dp[N] << endl;

	return 0;
}
