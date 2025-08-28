#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[11][11];
int ans;

void dfs(int n, int sum, int used) {
	if (__builtin_popcount(used) == 11) {
		ans = max(ans, sum);
		return;
	}

	for (int i=0;i<11;i++) {
		if (a[n][i] && !(used & (1<<i)))
			dfs(n+1, sum + a[n][i], used | (1 << i));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, t;
	cin >> t;
	while (t--) {
		for (i=0;i<11;i++)
			for (j=0;j<11;j++)
				cin >> a[i][j];
		ans = 0;
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
