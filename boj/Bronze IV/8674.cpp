#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, ans;
	cin >> a >> b;

	if (a % 2 == 0 || b % 2 == 0)
		ans = 0;
	else
		ans = min(a, b);
	cout << ans << endl;
	return 0;
}
