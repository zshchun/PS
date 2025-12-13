#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, cnt;
	cin >> n;
	vector<ll> a(n);
	for (i=0;i<n;i++)
		cin >> a[i];

	if (n < 3) {
		cout << n << endl;
		return 0;
	}

	ans = 0;
	sort(a.begin(), a.end());

	for (i=0;i<n - 2;i++) {
		k = a[i] + a[i+1];
		cnt = 2;
		for (j=i+2;j<n;j++) {
			if (k > a[j]) cnt++;
			else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}
