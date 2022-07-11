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
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		ll x = 1;
		ans = 0;
		for (i=0;i<=10;i++) {
			if (n >= x)
				ans = x;
			x *= 10;
		}
		if (n-ans == 0)
			ans = 0;
		else
			ans = n - ans; 

		cout << ans << endl;
	}
	return 0;
}
