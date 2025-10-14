#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans, i, n, m, k;
	cin >> n >> m >> k;
	i = k - m;
	ans = (n + i - 1) / i;
	cout << ans << endl;

	return 0;
}
