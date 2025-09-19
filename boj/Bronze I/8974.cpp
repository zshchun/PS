#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, j, k, ans = 0;
	cin >> n >> m;
	k = 1;
	i = 1;
	while (i <= 1000) {
		for (j=1;j<=k && i <= 1000;j++) {
			a[i++] = k;
		}
		k++;
	}
	for (i=n;i<=m;i++)
		ans += a[i];
	cout << ans << endl;
	return 0;
}
