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
	ll TC, i, j, k, c;
	cin >> TC;
	while(TC--) {
		cin >> n >> c;
		ans = 0;
		vector<ll> a(n+1);
		vector<ll> b(101);
		for (i=0;i<n;i++) {
			cin >> a[i];
			b[a[i]]++;
		}
		for (i=0;i<=100;i++) {
			if (b[i] > c)
				ans += c;
			else
				ans += b[i];
		}

		cout << ans << endl;
	}
	return 0;
}
