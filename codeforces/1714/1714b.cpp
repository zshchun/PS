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
		set<ll> s;
		vector<ll> a(n+1);
		for (i=1;i<=n;i++) {
			cin >> a[i];
		}
		for (i=n;i>=1;i--) {
			if (s.find(a[i]) == s.end()) {
				s.insert(a[i]);
			} else {
				ans = max(i, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
