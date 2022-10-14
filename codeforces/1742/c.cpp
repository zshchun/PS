#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		string ans;
		string s[8];
		for (i=0;i<8;i++)
			cin >> s[i];
		string c[8];
		for (i=0;i<8;i++) {
			for (j=0;j<8;j++) {
				c[j] += s[i][j];
			}
		}
		for (j=0;j<8;j++) {
			if (s[j] == "RRRRRRRR")
				ans = 'R';
			if (c[j] == "BBBBBBBB")
				ans = 'B';
		}

		cout << ans << endl;
	}
	return 0;
}
