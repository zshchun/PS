#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		ll ap, hp, t;
		cin >> ap >> hp >> n;
		ans = 0;
		vector<ll> a(n), b(n);
		for (i=0;i<n;i++) cin >> a[i];
		for (i=0;i<n;i++) cin >> b[i];
		ll dmg=0;
		for (i=0;i<n;i++) {
			t = (b[i] + ap - 1ull) / ap;
			dmg += t * a[i];
		}
		bool ok = false;
		for (i=0;i<n;i++) {
			if (hp - dmg + a[i] > 0)
				ok = true;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
