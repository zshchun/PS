#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll T, N, i, j, ans;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N;
		vector<ll> a(N);
		for (i=0;i<N;i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		j = 0;
		for (i=2;i<N;i+=2) {
			ans = max(ans, abs(a[i] - a[i-2]));
		}
		for (i=3;i<N;i+=2) {
			ans = max(ans, abs(a[i] - a[i-2]));
		}
		cout << ans << endl;
	}
	return 0;
}
