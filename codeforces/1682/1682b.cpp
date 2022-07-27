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
		ans = (1<<20)-1;
		vector<ll> a;
		for (i=0;i<n;i++) {
			cin >> z;
			if (z != i) a.push_back(z);
		}
		for (i=0;i<a.size();i++) {
			ans &= a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
