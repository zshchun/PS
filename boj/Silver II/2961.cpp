#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF INT_MAX

int a[11];
int b[11];
int N, ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, bitter, sour;
	cin >> N;
	// bitmask
	for (i=0;i<N;i++) {
		cin >> a[i] >> b[i];
	}
	for (i=1;i<1<<N;i++) {
		bitter = 0;
		sour = 1;
		for (j=0;j<N;j++) {
			if (i & (1<<j)) {
				sour *= a[j];
				bitter += b[j];
			}
		}
		ans = min(ans, abs(sour-bitter));
	}
	cout << ans << endl;
	return 0;
}
