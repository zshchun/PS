#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n;
ll m[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		memset(m, 0, sizeof(m));
		ll mx = 0;
		for (i=0;i<n;i++) {
			cin >> x;
			if (!m[x]) ans++;
			m[x]++;
		}
		ll cnt = 0;
		for (i=0;i<10001;i++) {
			if (m[i] && m[i] % 2 == 0) cnt++;
		}
		if (cnt % 2 == 1) ans--;
		cout << ans << endl;
	}
	return 0;
}
