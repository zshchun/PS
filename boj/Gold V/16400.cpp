#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N;
bool nprime[40001];
ll dp[40001];
vector<ll> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> N;
	nprime[0] = nprime[1] = 1;
	for (i=2;i<=40000;i++) {
		if (nprime[i]) continue;
		for (j=i+i;j<=40000;j+=i)
			nprime[j] = 1;
	}
	for (i=2;i<=N;i++)
		if (!nprime[i])
			prime.push_back(i);

	dp[0] = 1;
	for (ll &p : prime) {
		for (i=p;i<=N;i++) {
			dp[i] += dp[i - p];
			dp[i] %= 123456789;
		}
	}
	cout << dp[N] << endl;
	return 0;
}
