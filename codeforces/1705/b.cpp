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
		ans = 0;
		for (i=0;i<n-1;i++) {
			cin >> z;
			if (ans && z == 0)
				ans++;
			ans += z;
		}
		cin >> z;
		cout << ans << endl;
	}
	return 0;
}
