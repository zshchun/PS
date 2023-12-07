#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[5][5][100001];

#define LR(l, r) ((1 << (r-1)) | (1 << (l-1)))
#define L(l) (1 << (l-1))

int move(int from, int to) {
	if (from == 0)
		return 2;
	if (from == to)
		return 1;
	if (abs(from - to) == 2)
		return 4;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, i, j, N, l, r, ans = INF;
	vector<int> a;
	while (1) {
		cin >> x;
		if (x == 0)
			break;
		a.push_back(x);
	}
	N = a.size();
	memset(dp, 0x33, sizeof(dp));
	dp[0][0][0] = 0;

	for (i=1;i<=N;i++) {
		int x = a[i-1];
		for (l=0;l<5;l++) {
			for (r=0;r<5;r++) {
				dp[x][r][i] = min(dp[x][r][i], dp[l][r][i-1] + move(l, x));
				dp[l][x][i] = min(dp[l][x][i], dp[l][r][i-1] + move(r, x));
			}
		}
	}

	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			ans = min(ans, dp[i][j][N]);
		}
	}
	cout << ans << endl;
	return 0;
}
