#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, ans;
int a[1001];
int dp[1001];
int dpr[1001];
int ans1[1001];
int ans2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, v;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	for (i=0;i<N;i++) {
		int n = a[i];
		for (j=0, v=0;j<n;j++) {
			if (v < dp[j])
				v = dp[j];
		}
		if (v + 1 > dp[n]) {
			dp[n] = v + 1;
		}
		ans1[i] = dp[n];
	}
	for (i=N-1;i>=0;i--) {
		int n = a[i];
		for (j=0, v=0;j<n;j++) {
			if (v < dpr[j])
				v = dpr[j];
		}
		if (v + 1 > dpr[n]) {
			dpr[n] = v + 1;
		}
		ans2[i] = dpr[n];
	}
	for (i=0;i<N;i++) {
		if (ans1[i]+ans2[i] > ans)
			ans = ans1[i]+ans2[i]-1;
	}

	cout << ans << '\n';
	return 0;
}
