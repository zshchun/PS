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
		ans = 0;
		ll ti;
		cin >> ti;
		for (i=1;i<4;i++) {
			cin >> x;
			if (x > ti) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
