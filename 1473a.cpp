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
	ll T, i, j, x, v, ans;
	cin >> T;
	while(T--) {
		ll d;
		cin >> n >> d;
		vector<ll> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << (a.back() <= d || a[0] + a[1] <= d ? "YES" : "NO") << endl;
	}
	return 0;
}
