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
	ll s, t;
	cin >> n >> m;
	ans = 0;
	vector<ll> a(n);
	vector<ll> h(n);
	vector<ll> hr(n);
	for (i=0;i<n;i++)
		cin >> a[i];
	for (i=1;i<n;i++) {
		if (a[i-1] > a[i])
			h[i] = h[i-1] + a[i-1] - a[i];
		else
			h[i] = h[i-1];
	}
	for (i=n-2;i>=0;i--) {
		if (a[i+1] > a[i])
			hr[i] = hr[i+1] + a[i+1] - a[i];
		else
			hr[i] = hr[i+1];
	}
	for (i=0;i<m;i++) {
		cin >> s >> t;
		s--;t--;
		if (s <= t)
			cout << h[t]-h[s] << endl;
		else
			cout << hr[t]-hr[s] << endl;
	}
	return 0;
}
