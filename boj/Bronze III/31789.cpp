#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, x, s, c, p, ans = false;
	cin >> n;
	cin >> x >> s;
	for (i=0;i<n;i++) {
		cin >> c >> p;
		if (x >= c && s < p)
			ans = true;
	}
	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
