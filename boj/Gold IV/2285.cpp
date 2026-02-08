#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, ans;
ll sum[100002];
vector<pa> v;

ll get_left(ll i) {
	return sum[i-1];
}

ll get_right(ll i) {
	return sum[N] - sum[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, l, r, d;
	cin >> N;
	v.resize(N+1);
	for (i=1;i<=N;i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin()+1, v.end());

	for (i=1;i<=N;i++)
		sum[i] = sum[i-1] + v[i].second;

	for (i=1;i<=N;i++) {
		if (sum[i] * 2 >= sum[N]) {
			ans = v[i].first;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}
