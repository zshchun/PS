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
	ll T, i, j, k, x, v, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		vector<ll> a;
		char c;
		ans = 2e6;
		a.push_back(0);
		for (i=0;i<n;i++) {
			cin >> c;
			a.push_back(a.back()+(c == 'W'));
		}
		for (i=0;i<=n-k;i++) {
			ans = min(ans, a[i+k] - a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
