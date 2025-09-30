#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll r, c, n;
	cin >> r >> c >> n;
	r = (r + n - 1) / n;
	c = (c + n - 1) / n;
	cout << r * c << endl;
	return 0;
}
