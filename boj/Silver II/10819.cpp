#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll n;
ll a[9];
ll used[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, ans = 0;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	do {
		ll sum = 0;
		for (i=1;i<n;i++) {
			sum += abs(a[i-1] - a[i]);
		}
		ans = max(sum, ans);
	} while (next_permutation(a, a+n));

	cout << ans << endl;

	return 0;
}
