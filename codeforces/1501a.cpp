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
		vector<ll> b(n);
		vector<ll> tm(n);
		ans = 0;
		for (i=0;i<n;i++)
			cin >> a[i] >> b[i];
		for (i=0;i<n;i++)
			cin >> tm[i];
		ll g = 0;
		for (i=0;i<n-1;i++) {
			ll md = (b[i]-a[i]+1)/2;
			a[i] += g + tm[i];
			ll c = max(a[i]+md, b[i]);
			if (b[i] < c)
				g = c-b[i];
			else g = 0;
		}
		cout << g+tm[n-1]+a[n-1] << endl;
	}
	return 0;
}
