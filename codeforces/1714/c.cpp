#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 1234567890ll;
		for (i=1;i<(1<<10);i++) {
			l = 0, r = 0;
			for (j=0;j<9;j++) {
				if (i & (1<<j)) {
					l += j+1;
				}
			}
			if (l == n) {
				for (j=0;j<9;j++) {
					if (i & (1<<j)) {
						r = r * 10 + (j+1);
					}
				}
				ans = min(ans, r);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
