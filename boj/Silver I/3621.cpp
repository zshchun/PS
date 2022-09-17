#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll a[100001];
int main() {
	ll i, j, k, N, D, ans = 0;
	cin >> N >> D;
	for (i=0;i<N;i++) {
		cin >> j;
		a[j]++;
	}
	for (i=0;i<=N;i++) {
		j = 0;
		k = a[i];
		while (k > D) {
			j += k / D;
			k = (k / D) + (k % D);
		}
		ans += j;
	}
	cout << ans << endl;
	return 0;
}
