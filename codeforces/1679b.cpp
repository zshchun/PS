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
	ll q;
	cin >> n >> q;
	ans = 0;
	vector<ll> a(n+1);
	set<ll> s;
	k = 0;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		ans += a[i];
		s.insert(i);
	}
	for (i=0;i<q;i++) {
		cin >> z;
		if (z == 2) {
			cin >> l;
			ans = l * n;
			s.clear();
			k = l;
		} else {
			cin >> l >> r;
			if (s.find(l) != s.end()) {
				ans = ans - a[l] + r;
			} else {
				s.insert(l);
				ans = ans - k + r;
			}
			a[l] = r;
		}
		cout << ans << endl;
	}
	return 0;
}
