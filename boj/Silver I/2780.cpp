#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll dp[1001][10];
vector<int> g[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, k, T;
	cin >> T;
	for (i=0;i<10;i++)
		dp[1][i] = 1;
	g[0] = {7};
	g[1] = {2, 4};
	g[2] = {1, 3, 5};
	g[3] = {2, 6};
	g[4] = {1, 5, 7};
	g[5] = {2, 4, 6, 8};
	g[6] = {3, 5, 9};
	g[7] = {4, 8, 0};
	g[8] = {5, 7, 9};
	g[9] = {6, 8};
	if (!T) return 0;
	for (i=2;i<=1000;i++) {
		for (k=0;k<10;k++) {
			for (int &j : g[k])
				dp[i][k] += dp[i-1][j];
			dp[i][k] %= 1234567;
		}
	}

	while (T--) {
		cin >> k;
		cout << accumulate(&dp[k][0], &dp[k][10], 0ull) % 1234567 << endl;
	}
	return 0;
}
