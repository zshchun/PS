#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, w, h, ans = 0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> h >> w;
		ans = max(ans, h * w);
	}
	cout << ans << endl;

	return 0;
}
