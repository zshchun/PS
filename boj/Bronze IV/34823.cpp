#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int y, c, p, ans;
	cin >> y >> c >> p;
	ans = min({y, c / 2, p});
	cout << ans << endl;
	return 0;
}
