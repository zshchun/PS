#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, k, ans;

vector<int> a;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n >> k;
	a.resize(n);
	for (i=0;i<n;i++)
		cin >> a[i];
	fill_n(dp, 100001, INF);
//	sort(a.begin(), a.end());
	dp[0] = 0;

	for (int x : a) {
		for (i=k;i>=x;i--) {
			dp[i] = min(dp[i], dp[i-x] + 1);
		}
	}

	if (dp[k] == INF)
		cout << "-1\n";
	else
		cout << dp[k] << endl;
	
	return 0;
}
