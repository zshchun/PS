#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, a, b, c, d, ans[10] = {0, };
	cin >> a >> b >> c;
	d = a * b * c;
	while (d) {
		ans[d%10]++;
		d /= 10;
	}
	for (i=0;i<=9;i++)
		cout << ans[i] << endl;
	return 0;
}
