#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, i, l, v;
	char c;
	cin>>t;
	while(t--) {
		cin>>n;
		for (l=0,i=0;i<n;i++) {
			cin>>c;
			if (1+(c-'0') != l)
				v = 1;
			else
				v = 0;
			l = v+(c-'0');
			cout <<v;
		}
		cout<<"\n";
	}

	return 0;
}
