#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, a, b, c;
ll sum[1000001]; // prefix sum
ll dp[1000001];
ll line[1000001];

#define F(x) ((a * (x) * (x)) + (b * (x)) + c)
double inter(ll i, ll j) {
	ll sum_jjii = sum[j] * sum[j] - sum[i] * sum[i];
	ll sum_ji = sum[j] - sum[i];
	return (double)(dp[j] - dp[i] + a * sum_jjii - b * sum_ji) / (2 * a * sum_ji);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, s, e;
	cin >> n >> a >> b >> c;
	for (i=1;i<=n;i++) {
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	s = 0;
	e = 1;
	for (i=1;i<=n;i++) {
		while (s+1 < e && inter(line[s], line[s+1]) < sum[i]) s++;
		dp[i] = F(sum[i] - sum[line[s]]) + dp[line[s]];
		while (s+1 < e && inter(line[e-2], line[e-1]) > inter(line[e-1], i)) e--;
		line[e++] = i;
	}

	cout << dp[n] << endl;
	return 0;
}
