#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[10001];
vector<int> a;
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> n >> k;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v <= 10000)
			a.push_back(v);
	}
	dp[0] = 1;
	for (int &j : a) {
		for (i=j;i<=10000;i++) {
			dp[i] += dp[i-j];
		}
	}
	cout << dp[k] << endl;
	return 0;
}
