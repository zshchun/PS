#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, j, s;
	vector<long> a;
	a.reserve(10000000);
	cin>>n;
	for (i=2;i*i<=n;i++) {
		for(j=i*i;j<=n;j*=i) {
			a.push_back(j);
		}
	}
	sort(a.begin(), a.end());
	s = unique(a.begin(), a.end()) - a.begin();
	cout << n-s << "\n";
	return 0;
}
