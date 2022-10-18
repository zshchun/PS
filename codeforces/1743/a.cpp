#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		ans = 0;
		vector<ll> a(10, 1);
		for (i=0;i<n;i++) {
			cin >> j;
			a[j] = 0;
		}
		for (i=0;i<10;i++) {
			if (a[i] == 0) continue;
			for (j=i+1;j<10;j++) {
				if (a[j] == 0) continue;
				ans += 6;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
