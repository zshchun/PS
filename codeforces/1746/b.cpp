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
		ans = 0;
		deque<ll> one;
		deque<ll> zero;
		for (i=0;i<n;i++) {
			cin >> j;
			if (j) one.push_back(i);
			else zero.push_back(i);
		}
		while (!one.empty() && !zero.empty() && zero.back() > one.front()) {
			ans++;
			zero.pop_back();
			one.pop_front();
		}
		cout << ans << endl;
	}
	return 0;
}
