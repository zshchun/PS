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
		cin >> n;
		ans = 0;
		vector<ll> a;
		ll o = 0, e = 0;
		ll mn = 63;
		for (i=0;i<n;i++) {
			cin >> z;
			if (z&1) o++;
			else {
				e++;
				k = __builtin_ffs(z)-1;
				if (mn > k)
					mn = k;
			}
		}
		if (e == n) {
			cout << mn + n-1 << endl;
			continue;
		}
		cout << e << endl;
	}
	return 0;
}
