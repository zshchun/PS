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
		cin >> n >> m >> k;
		vector<ll> a(k);
		for (i=0;i<k;i++) {
			cin >> a[i];
		}
		ll maxn = 0, maxm = 0;
		bool ok = false;
		bool oddn = false;
		bool oddm = false;
		for (i=0;i<k;i++) {
			if (a[i]/n >= 2) {
				maxm += a[i] / n;
				if (a[i]/n >= 3) oddm = 1;
			}
			if (a[i]/m >= 2) {
				maxn += a[i] / m;
				if (a[i]/m >= 3) oddn = 1;
			}
			if ((oddn && maxn >= n) || (oddm && maxm >= m) || (m%2==0 && maxm >= m) || (n%2 == 0 && maxn >= n)) {
				ok = true;
				break;
			}
		}
		if (ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
