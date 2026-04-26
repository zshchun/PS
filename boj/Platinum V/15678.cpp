#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789012345ll
ll N, D, ans = -INF;
ll dp[100001];
ll a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, prev;
	cin >> N >> D;
	deque<ll> dq(N);

	for (i=0;i<N;i++)
		cin >> a[i];

	for (i=0;i<N;i++) {
		while (!dq.empty() && dq.front() < i - D)
			dq.pop_front();

		if (!dq.empty() && dp[dq.front()] > 0)
			dp[i] = dp[dq.front()];
		dp[i] += a[i];
		ans = max(ans, dp[i]);

		while (!dq.empty() && dp[dq.back()] <= dp[i])
			dq.pop_back();
		dq.push_back(i);
	}
	cout << ans << endl;
	return 0;
}
