#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MAX_BIT 20

int a[200001];
int dp[MAX_BIT][200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, q, i, j, k, n, x;
	cin >> m;
	for (i=1;i<=m;i++)
		cin >> dp[0][i];

	for (i=1;i<=MAX_BIT;i++)
		for (j=1;j<=m;j++)
			dp[i][j] = dp[i-1][dp[i-1][j]];

	cin >> q;
	for (i=0;i<q;i++) {
		cin >> n >> x;
		k = x;
		for (j=0;j<MAX_BIT;j++) {
			if (n & (1 << j))
				k = dp[j][k];
		}
		cout << k << endl;
	}
	
	return 0;
}
