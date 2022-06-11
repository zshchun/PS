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
	ll T, i, j, x, v, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		ll mx = 0;
		for (i=0;i<n;i++) {
			cin >> b[i];
			if (a[i] - b[i] > mx)
				mx = a[i]-b[i];
		}
		for (i=0;i<n;i++) {
			if (b[i] != 0 && a[i]-b[i] != mx)
				break;
		}
		if (i == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
