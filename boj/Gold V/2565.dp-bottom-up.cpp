#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
int dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, u, v;
	cin >> N;

	vector<pa> a;
	for (i=0;i<N;i++) {
		cin >> u >> v;
		a.push_back(pa(u, v));
	}

	sort(a.begin(), a.end());

	fill(dp, dp+101, 1);

	for (i=1;i<N;i++) {
		for (j=0;j<i;j++) {
			if (a[j].second < a[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}
	cout << N - ans << endl;

	return 0;
}
