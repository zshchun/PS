#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int e, f, c, ans = 0, i;
	cin >> e >> f >> c;
	i = e + f;
	while (i >= c) {
		ans += i / c;
		i = (i / c) + (i % c);
	}

	cout << ans << endl;
	return 0;
}
