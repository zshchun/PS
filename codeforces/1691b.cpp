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
		cin >> n;
		map<ll,ll> a;
		for (i=0;i<n;i++) {
			cin >> z;
			a[z]++;
		}
		bool ok = true;
		for (auto &it : a)
			if (it.second == 1) {
				ok = false;
				break;
			}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		ll idx = 1;
		for (auto &it : a) {
			k = it.second;
			for (i=0;i<k;i++) {
				cout << ((i+k-1)%k)+idx << ' ';
			}
			idx += k;
		}
		cout << endl;
	}
	return 0;
}
