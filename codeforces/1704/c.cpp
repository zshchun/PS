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
		cin >> n >> m;
		ans = 0;
		vector<ll> a(m);
		for (i=0;i<m;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		ll x = a[0] - 1 + n - a[m-1];
		for (i=0;i<m-1;i++)
			a[i] = a[i+1] - a[i] - 1;
		a[m-1] = x;
		sort(a.begin(), a.end(), greater<ll>());
		for (i=0;i<m;i++) {
			if (a[i] <= 4 * i) continue;
			if (a[i]-4*i <= 1)
				ans++;
			else
				ans += a[i] - 4*i - 1;
		}
		cout << n - ans << endl;
	}
	return 0;
}
