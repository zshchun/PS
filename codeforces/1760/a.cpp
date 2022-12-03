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
		vector<ll> a;
		for (i=0;i<3;i++) {
			cin >> j;
			a.push_back(j);
		}
		sort(a.begin(), a.end());
		cout << a[1] << endl;
	}
	return 0;
}
