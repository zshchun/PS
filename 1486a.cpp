#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, i, s;
	ll a[101];
	cin>>t;
	while(t--) {
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		s = a[1];
		for(i=2;i<=n;i++) {
			s += a[i];
			if (s < ((i-1)*i/2))
				break;
		}
		if (i == 1 || i > n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
