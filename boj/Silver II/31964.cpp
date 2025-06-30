#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define In 123456789

int n, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, p;
	cin >> n;
	vector<int> x(n+1);
	vector<int> t(n+1);
	for (i=1;i<=n;i++)
		cin >> x[i];
	for (i=1;i<=n;i++)
		cin >> t[i];
	ans = x[n];
	ans = max(x[n], t[n]);

	for (i=n-1;i>=0;i--) {
		int d = x[i+1] - x[i];
		ans = max(ans + d, t[i]);
	}
	cout << ans << endl;
	return 0;
}
