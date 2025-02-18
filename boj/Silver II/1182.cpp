#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, s, ans;
ll a[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, t;
	cin >> n >> s;
	for (i=0;i<n;i++)
		cin >> a[i];
	for (i=1;i<(1<<n);i++) {
		t = 0;
		for (j=0;j<n;j++) {
			if (i & (1<<j))
				t += a[j];
		}
		if (s == t)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
