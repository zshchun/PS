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
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (max(l1, l2) <= min(r1, r2)) {
			cout << max(l1,l2) << endl;
		} else {
			cout << l1+l2 << endl;
		}
	}
	return 0;
}
