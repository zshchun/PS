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
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		ans = 1;
		for (i=0;i<n;i++) {
			cin >> x;
			a[x] = i;
		}
		l = r = a[0];
		for (i=1;i<n;i++) {
			if (a[i] < l) l = a[i];
			else if (r < a[i]) r = a[i];
			else {
				ans = ans * (r - l + 1 - i) % MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
