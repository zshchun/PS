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
		cin >> n >> m;
		ans = 1e5+1;
		vector<ll> a(n+1);
		vector<ll> d(n+1);
		vector<ll> u(m), v(m);
		for (i=1;i<=n;i++) {
			cin >> a[i];
		}
		for (i=0;i<m;i++) {
			cin >> u[i] >> v[i];
			d[u[i]]++;
			d[v[i]]++;
		}
		if (m%2 == 0) {
			cout << 0 << endl;
			continue;
		}
		for (i=1;i<=n;i++) {
			if (d[i]%2 && a[i] < ans)
				ans = a[i];
		}
		for (i=0;i<m;i++) {
			if (d[u[i]]%2 == 0 && d[v[i]]%2 == 0 && a[u[i]]+a[v[i]] < ans)
				ans = a[u[i]]+a[v[i]];
		}
		cout << ans << endl;
	}
	return 0;
}
