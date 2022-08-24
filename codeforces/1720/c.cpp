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
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		ans = 0;
		vector<string> s(n);
		for (i=0;i<n;i++) {
			cin >> s[i];
			for (j=0;j<m;j++) {
				if (s[i][j] == '1') ans++;
			}
		}
		ll mn = 4;
		ll sum;
		for (i=0;i<n-1;i++) {
			for (j=0;j<m-1;j++) {
				if (j == 0) {
					sum = s[i][0] + s[i][1] + s[i+1][0] + s[i+1][1] - '0'*4;
				} else {
					sum -= s[i][j-1] + s[i+1][j-1] - '0'*2;
					sum += s[i][j+1] + s[i+1][j+1] - '0'*2;
				}
				mn = min(sum, mn);
			}
		}
		if (mn >= 3)
			cout << ans-(mn-2) << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
