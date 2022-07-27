#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> x) {
	sort(x.begin(), x.end());
	return x[x.size()/2] - x[(x.size()-1)/2] + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<ll> x(n), y(n);
		for (i=0;i<n;i++) cin>>x[i]>>y[i];
		cout << solve(x) * solve(y) << "\n";
	}
	return 0;
}
