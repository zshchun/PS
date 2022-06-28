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
		ans = 0;
		ll e = 0, o = 0;
		for (i=0;i<n;i++) {
			cin >> x;
			if (x % 2)
				o++;
			else
				e++;
		}
		ans = min(o, e);
		cout << ans << endl;
	}
	return 0;
}
