#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, ans = 0;
	cin >> N;
	vector<pa> a(N);

	for (i=0;i<N;i++)
		cin >> a[i].first;

	for (i=0;i<N;i++)
		cin >> a[i].second;

	sort(a.begin(), a.end(), [](pa &lhs, pa &rhs) {
		return lhs.second < rhs.second;
	});

	for (i=0;i<N;i++) {
		ans += a[i].first + a[i].second * i;
	}
	cout << ans << endl;

	return 0;
}
