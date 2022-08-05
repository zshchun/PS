#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		if (n&1)
			cout << "Mike\n";
		else {
			ll mm = 1e10;
			ll p = 0;
			for (i=0;i<n;i++) {
				if (a[i] < mm) {
					mm = a[i];
					p = i;
				}
			}
			if (p % 2)
				cout << "Mike\n";
			else
				cout << "Joe\n";
		}
	}
	return 0;
}
