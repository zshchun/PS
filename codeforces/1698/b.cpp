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
		cin >> n >> k;
		vector<ll> a(n);
		ans = 0;
		for (i=0;i<n;i++)
			cin >> a[i];
		if (k == 1) {
			cout << (n-1)/2 << endl;
			continue;
		}
		for (i=1;i<n-1;i++) {
			if (a[i] > a[i-1]+a[i+1])
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
