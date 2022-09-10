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
		cin >> n;
		set<ll> ans;
		for (i=0;i<n;i++) {
			cin >> j;
			while (j%10 != 2 && j%10 != 0) {
				j += (j%10);
			}
			if (j%10 == 0)
				ans.insert(j);
			else
				ans.insert(j % 20);
		}
		if (ans.size() == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
