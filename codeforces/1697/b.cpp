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
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> r(n+1);
	for (i=0;i<n;i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	partial_sum(a.begin(), a.end(), r.begin()+1);
	r[0] = 0;
	for (i=0;i<m;i++) {
		ans = 0;
		ll y;
		cin >> x >> y;
		cout << r[n-x+y]-r[n-x] << endl;
	}
	return 0;
}
