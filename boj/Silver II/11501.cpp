#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, N, i, k, ans;
	cin >> T;
	for (k=0;k<T;k++) {
		cin >> N;
		vector<ll> a(N);
		ans = 0;

		for (i=0;i<N;i++) {
			cin >> a[N-1-i];
		}
		ll mx = a[0];

		for (i=1;i<N;i++) {
			if (a[i] <= mx) {
				ans += mx - a[i];
			} else {
				mx = a[i];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
