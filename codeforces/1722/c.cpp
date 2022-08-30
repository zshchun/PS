#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans[3];

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> v(3);
		vector<vector<string>> s(3);
		map<string, ll> a;
		string y;
		for (i=0;i<3;i++) {
			for (j=0;j<n;j++) {
				cin >> y;
				a[y]++;
				s[i].push_back(y);
			}
		}
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 0;
		for (i=0;i<3;i++) {
			for (j=0;j<n;j++) {
				if (a[s[i][j]] == 2) {
					ans[i]++;
				} else if (a[s[i][j]] == 1) {
					ans[i] += 3;
				}
			}
		}
		for (i=0;i<3;i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
