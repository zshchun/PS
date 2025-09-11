#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, m, v;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		cin >> v;
		ans[0] = max(ans[0], v);
	}
	for (i=0;i<m;i++) {
		cin >> v;
		ans[1] = max(ans[1], v);
	}
	cout << ans[0] + ans[1] << endl;
	return 0;
}
