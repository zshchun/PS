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
	ll TC, i, j, k, l;
	cin >> TC;

	auto divide_all = [&](ll n) -> vector<pa> {
		vector<pa> a;
		for (i=0;i<n;i++) {
			cin >> j;
			l = 1;
			while (j % m == 0) {
				j /= m;
				l *= m;
			}
			if (!a.empty() && a.back().first == j)
				a.back().second += l;
			else {
				a.push_back(pa(j, l));
			}
		}
		return a;
	};
	while(TC--) {
		cin >> n >> m;
		vector<pa> a = divide_all(n);
		cin >> k;
		vector<pa> b = divide_all(k);
		if (a == b)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
