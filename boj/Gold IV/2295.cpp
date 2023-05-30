#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, j, k, mx = 0, ans = 0;
	cin >> N;
	vector<ll> a(N);
	unordered_set<ll> sum;

	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			sum.insert(a[i] + a[j]);
		}
	}

	sort(a.begin(), a.end(), greater<ll>());

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (sum.find(a[i] - a[j]) != sum.end()) {
				ans = max(ans, a[i]);
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
