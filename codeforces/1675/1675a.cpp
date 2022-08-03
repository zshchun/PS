#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ll a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;
		l = max(x-a, 0ll);
		r = max(y-b, 0ll);
		if ((a-x >= 0 && b-y >= 0) || (l+r) <= c)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
