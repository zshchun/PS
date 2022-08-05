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
		cin >> n >> x;
		queue<pl> a;
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> v;
			a.push(pl(v, 1));
			ans += v;
		}
		while (!a.empty()) {
			auto p = a.front();
			a.pop();
			ll b = p.first;
			ll nr = p.second;
			if (b % x) break;
			else {
				ans += b * nr;
				a.push(pl(b / x, nr * x));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
