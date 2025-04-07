#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m, h;
vector<int> a[51];
int dp[51][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n >> m >> h;
	cin.ignore();
	string line;
	// knapsack
	for (i=1;i<=n;i++) {
		getline(cin, line);
		istringstream iss(line);
		while (iss >> j)
			a[i].push_back(j);
		sort(a[i].begin(), a[i].end());
	}

	for (i=0;i<=n;i++)
		dp[i][0] = 1;

	for (i=1;i<=n;i++) {
		for (j=1;j<=h;j++) {
			for (int &x : a[i]) {
				if (j < x) break;
				dp[i][j] += dp[i-1][j-x];
			}
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= 10007;
		}
	}

	cout << dp[n][h] << endl;

	return 0;
}
