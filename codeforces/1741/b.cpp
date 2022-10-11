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
		if (n == 3) {
			cout << "-1\n";
			continue;
		}
		if (n&1) {
			for (i=n-1;i<=n;i++)
				cout << i << ' ';
			for (i=1;i<n-1;i++)
				cout << i << ' ';
		} else {
			for (i=n;i>=1;i--)
				cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}
