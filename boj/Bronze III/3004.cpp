#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v = 1, h = 1, ans;
	int n, i;
	cin >> n;
	for (i=1;i<=n;i++) {
		if (v < h)
			v++;
		else
			h++;
	}
	ans = v * h;
	cout << ans << endl;
	return 0;
}
