#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c, d, ans;
	while (cin >> c >> d) {
		if (c == 0 && d == 0)
			break;
		ans = c * 30 + d * 40;
		ans = min(ans, c * 35 + d * 30);
		ans = min(ans, c * 40 + d * 20);
		cout << ans << endl;
	}
	return 0;
}
