#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t(ll v) {
	ll a[12];
	ll n=0, a1, a2, i;
	while (v) {
		a[n] = v % 10;
		v /= 10;
		n++;
	}
	sort(a, a+n);
	for(i=0, a1=0;i<n;i++) {
		a1 = a1 * 10 + a[i];
	}
	for(i=n-1, a2=0;i>=0;i--) {
		a2 = a2 * 10 + a[i];
	}
	return a2 - a1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k, i, v;
	cin>>k>>n;

	for (i=0;i<n;i++) {
		k = t(k);
	}
	cout << k << "\n";
	return 0;
}
