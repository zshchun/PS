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
		for (i=0;i<n;i++) cin >> a[i];
		sort(a.begin(), a.end(), [&](const ll lhs, const ll rhs) {
			return lhs%2 < rhs%2;
		});
		for (i=0;i<n;i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
