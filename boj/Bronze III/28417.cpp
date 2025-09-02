#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, k, ans = 0;
	cin >> n;
	for (j=0;j<n;j++) {
		vector<int> a(2);
		cin >> a[0] >> a[1];
		sort(a.begin(), a.end());
		k = a.back();

		a.resize(5);
		for (i=0;i<5;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		k += a[3] + a[4];
		ans = max(ans, k);
	}
	cout << ans << endl;
	return 0;
}
