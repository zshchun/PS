#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		ans = 0;
		ll a1, a2, a3, a4;
		cin >> a1 >> a2 >> a3 >> a4;
		ll s = a1+a2+a3+a4;
		if (s == 4)
			ans = 2;
		else if (s > 0)
			ans = 1;
		cout << ans << endl;
	}
	return 0;
}
