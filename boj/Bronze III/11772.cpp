#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, x, ans = 0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> x;
		ans += pow(x/10, x%10);
	}
	cout << ans << endl;

	return 0;
}
