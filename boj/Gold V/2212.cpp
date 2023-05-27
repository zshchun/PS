#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, K, i;
	cin >> N >> K;

	ll ans = 0;
	vector<ll> a(N);
	vector<ll> acc;

	for (i=0;i<N;i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	for (i=1;i<N;i++)
		acc.push_back(a[i] - a[i-1]);

	sort(acc.begin(), acc.end());

	for (i=0;i<acc.size()-(K-1);i++) {
		if (i >= acc.size())
			break;
		ans += acc[i];
	}

	cout << ans << endl;

	return 0;
}
