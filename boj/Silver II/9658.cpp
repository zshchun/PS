#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N;
	cin >> N;
	dp[2] = 1;
	dp[4] = 1;
	for (i=5;i<=N;i++) {
		if (min({dp[i-1], dp[i-3], dp[i-4]}) != 1) {
			dp[i] = 1;
		}
	}
	if (dp[N])
		cout << "SK\n";
	else
		cout << "CY\n";
	return 0;
}
