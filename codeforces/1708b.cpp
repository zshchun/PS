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
		cin >> n >> l >> r;
		vector<ll> a(n+1);
		bool ok = true;
		for (i=1;i<=n;i++) {
			ll x = ((l-1) / i+1) * i;
			if (x > r) {
				ok = false;
				break;
			}
			a[i] = x;
		}
		if (ok) {
			cout << "YES\n";
			for (i=1;i<=n;i++)
				cout << a[i] << ' ';
			cout << endl;
		} else
			cout << "NO\n";

	}
	return 0;
}
