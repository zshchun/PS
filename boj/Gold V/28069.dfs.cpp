#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, K, ans = 0;
int dp[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> N >> K;
	fill_n(dp, 1000005, INF);
	dp[0] = 0;
	for (i=0;i<N;i++) {
		if (i+1 <= N)
			dp[i+1] = min(dp[i+1], dp[i] + 1);
		if (i+i/2 <= N)
			dp[i+i/2] = min(dp[i+i/2], dp[i] + 1);
	}

	if (dp[N] <= K)
		cout << "minigimbob" << endl;
	else
		cout << "water" << endl;

	return 0;
}
