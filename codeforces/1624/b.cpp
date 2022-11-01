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
		ll a, b, c;
		cin >> a >> b >> c;
		ll bb = b * 2;
		ll ac = a + c;
		if (!(ac % bb) || (bb > c && !((bb-c) % a)) || (bb > a && !((bb - a) % c)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
