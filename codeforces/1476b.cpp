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
	ll T, i, j, k, x, y, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		ans = 0;
		vector<ll> a(n);
		cin >> m;
		for (i=1;i<n;i++) {
			cin >> y;
			ans = max(ans, (y*100 - k * m + k-1) / k);
			m += y;
		}
		cout << ans << endl;
	}
	return 0;
}
