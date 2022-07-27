#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a;
		for (i=0;i<n;i++) {
			cin >> x;
			a.push_back(x);
		}
		bool ok = true;
		for (i=0;i<n;i++) {
			x = sqrt(a[i]);
			if (x*x != a[i]) {
				ok = false;
			}
		}
		if (ok)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
