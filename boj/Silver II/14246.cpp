#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[100001];
ll sum, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, j, k;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];
	cin >> k;
	for (i=0,j=0;i<n;i++) {
		while (j < n && sum + a[j] <= k) {
			sum += a[j];
			j++;
		}
		ans += n - j;
		sum -= a[i];
	}
	cout << ans << endl;

	return 0;
}
