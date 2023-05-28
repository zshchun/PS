#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

bool v[2600000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll sum, i, j, bit, N, mx = 0, ans = 0;
	cin >> N;
	vector<ll> a(N);

	for (i=0;i<N;i++) {
		cin >> a[i];
		mx += a[i];
	}

	for (i=0;i<(1 << (N*2));i++) {
		sum = 0;
		for (j=0;j<N;j++) {
			bit = (i >> (j * 2)) & 0x3;
			if (bit == 3) break;
			if (bit == 0) continue;
			if (bit == 1) {
				sum += a[j];
			} else {
				sum -= a[j];
			}
		}
		if (sum > 0)
			v[sum] = 1;
	}

	for (i=1;i<=mx;i++) {
		if (v[i] == 0) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
