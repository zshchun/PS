#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[8002];
ll a[500001];
#define MIN (1LL<<63)
#define MAX (1LL<<62)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, v, i, mn=MAX, mx=MIN, s=0, median=0, mode=0, range=0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		s += v;
		a[i] = v;
		if (v > mx)
			mx = v;
		if (v < mn)
			mn = v;
		cnt[v+4000]++;
		if (cnt[v+4000] > cnt[mode+4000])
			mode = v;
	}
	vector<ll> z;
	for (i=0;i<8001;i++) {
		if (cnt[i] == cnt[mode+4000])
			z.push_back(i-4000);
	}
	if (z.size() > 1) {
		mode = z[1];
	}
	sort(a, a+n);
	if ((n%2) == 0) {
		median = round((a[(n-1)/2] + a[(n)/2]) /2.0);
	} else {
		median = a[n/2];
	}
	if (mn == MAX) mn = 0;
	if (mx == MIN) mx = 0;

		cout << round(s / (float)n) << "\n";
	cout << median << "\n";
	cout << mode << "\n";
	cout << a[n-1] - a[0] << "\n";

	return 0;
}
