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
		for (i=0;i<n;i++) {
			if (i%2 == 0)
				cout << 1 + (i/2) << ' ';
			else
				cout << n - (i/2) << ' ';
		}
		cout << endl;
	}
	return 0;
}
