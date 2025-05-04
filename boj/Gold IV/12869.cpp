#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N;
int ans = INF;
int dp[61][61][61];

void dfs(int n, int a, int b, int c) {
	if (a <= 0 && b <= 0 && c <= 0) {
		ans = min(ans, n);
		return;
	}
	if (a <= 0) a = 0;
	if (b <= 0) b = 0;
	if (c <= 0) c = 0;

	if (dp[a][b][c] && dp[a][b][c] <= n) return;
	dp[a][b][c] = n;

	dfs(n+1, a-9, b-3, c-1);
	dfs(n+1, a-9, b-1, c-3);
	dfs(n+1, a-3, b-9, c-1);
	dfs(n+1, a-3, b-1, c-9);
	dfs(n+1, a-1, b-9, c-3);
	dfs(n+1, a-1, b-3, c-9);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[3];
	int i, v;
	cin >> N;
	a[0] = a[1] = a[2] = 0;
	for (i=0;i<N;i++)
		cin >> a[i];
	
	dfs(0, a[0], a[1], a[2]);

	cout << ans << endl;

	return 0;
}
