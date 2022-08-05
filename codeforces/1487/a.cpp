#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, i;
	int h[100];
	cin>>t;
	while(t--) {
		cin>>n;
		for (i=0;i<n;i++)
			cin>>h[i];
		sort(h, h+n);
		for (i=0;h[i] == h[i+1] && i<n-1;i++) {
			;
		}
		cout << n-(i+1) << '\n';
	}
	return 0;
}
