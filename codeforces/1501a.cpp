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
		vector<ll> a(n+1);
		vector<ll> b(n+1);
		vector<ll> tm(n+1);
		a[0] = b[0] = 0;
		for (i=1;i<=n;i++)
			cin >> a[i] >> b[i];
		for (i=1;i<=n;i++)
			cin >> tm[i];
		ll cur = 0;
		for (i=1;i<=n;i++) {
			cur += a[i] - b[i-1] + tm[i];
			if (i == n) break;
			cur = max(cur+(b[i]-a[i]+1)/2, b[i]);
		}
		cout << cur << endl;
	}
	return 0;
}
