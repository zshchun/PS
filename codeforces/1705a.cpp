#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ll x;
		cin >> n >> x;
		vector<ll> a(n*2);
		ans = 0;
		for (i=0;i<n*2;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (i=0;i<n;i++) {
			if (a[i+n]-a[i] < x)
				break;
		}
		if (i == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
