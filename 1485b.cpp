#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, t, k, i, c, a, b;
	cin>>n>>t>>k;
	int *q = new int[n+1];
	for(i=1;i<=n;i++) {
		cin>>q[i];
	}
	while(t--) {
		cin>>a>>b;
		c = q[a]-1 + k - q[b] + 2 * ((q[b] - q[a] + 1) - (b-a+1));
		cout<<c<<"\n";
	}

	return 0;
}
