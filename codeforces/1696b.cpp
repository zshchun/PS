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
		vector<ll> a(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		if (a[0] != 0) ans++;
		for (i=1;i<n;i++) {
			if (a[i-1] == 0 && a[i])
				ans++;
		}
		if (ans >= 2) ans = 2;
		cout << ans << endl;
	}
	return 0;
}
