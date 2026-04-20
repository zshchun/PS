#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int N, T, ans;
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> T;
	vector<pi> a(N);
	for (i=0;i<N;i++)
		cin >> a[i].first >> a[i].second;

	// knapsack
	for (j=0;j<N;j++) {
		auto [time, score] = a[j];
		for (i=T;i>=time;i--)
			dp[i] = max(dp[i], dp[i-time] + score);
	}
	cout << dp[T] << endl;

	return 0;
}
