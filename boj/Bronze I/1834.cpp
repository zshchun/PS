#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, n;
	cin >> n;
	for (i=1;i<n;i++)
		ans += i * n + i;
	cout << ans << endl;
	return 0;
}
