#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789012ULL
ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, min = INF;
	ll l, r, sum;
	ll ans[2];
	cin >> N;
	vector<ll> a(N);
	for (i=0;i<N;i++)
		cin >> a[i];
	
	l = 0;
	r = N - 1;

	while (l < r) {
		sum = a[l] + a[r];
		if (min > abs(sum)) {
			min = abs(sum);
			ans[0] = a[l];
			ans[1] = a[r];
		}
		if (sum < 0)
			l++;
		else
			r--;
	}
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
