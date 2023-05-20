#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll a[2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll i, j, N, v, x;
	ll ans = 0;

	cin >> N;
	unordered_map<ll,ll> s;
	unordered_set<ll> us;

	for (i=0;i<N;i++) {
		cin >> a[i];
		s[a[i]]++;
	}

	for (i=0;i<N;i++) {
		for (j=i+1;j<N;j++) {
			x = a[i] + a[j];
			if (a[i] == 0 && a[j] == 0) {
				if (s[0] > 2)
					us.insert(x);
			} else if (a[i] == 0 || a[j] == 0) {
				if (s[x] > 1)
					us.insert(x);
			} else if (s[x] > 0) {
				us.insert(x);
			}
		}
	}

	for (i=0;i<N;i++) {
		if (us.count(a[i]) > 0)
			ans++;
	}

	cout << ans << endl;
	return 0;
}
