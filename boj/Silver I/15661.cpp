#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[21][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, x, y, i, j, k, b1, b2, ans = INF;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];
	
	for (i=0;i<(1<<N);i++) {
		x = 0; // 0
		y = 0; // 1
		for (j=0;j<N;j++) {
			b1 = i & (1<<j);
			for (k=j+1;k<N;k++) {
				b2 = i & (1<<k);
				if (!!b1 == !!b2) {
					if (b1) {
						y += a[j][k] + a[k][j];
					} else {
						x += a[j][k] + a[k][j];
					}
				}
			}
		}
		ans = min(ans, abs(x-y));
	}
	cout << ans << endl;

	return 0;
}
