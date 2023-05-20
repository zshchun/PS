#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll a[2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, j, x, s, e, ans = 0;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	sort(a, a+N);

	for (i=0;i<N;i++) {
		s = 0;
		e = N - 1;
		x = a[i];
		while (s < e) {
			if (a[s] + a[e] > x) {
				e--;
			} else if (a[s] + a[e] < x) {
				s++;
			} else if (s == i) {
				s++;
			} else if (e == i) {
				e--;
			} else {
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
