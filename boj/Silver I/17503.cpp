#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF (1ull<<40)
ll N, M, K;
vector<pa> a;

bool check(ll x) {
	ll i, total = 0, cnt = 0;
	for (i=0;i < K && cnt < N;i++) {
		if (a[i].second <= x) {
			total += a[i].first;
			cnt++;
			if (cnt == N && total >= M)
				break;
		}
	}
	if (cnt == N && total >= M)
		return true;
	return false;
}
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, v, l, r, m;
	cin >> N >> M >> K;
	a.resize(K);

	for (i=0;i<K;i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end(), greater());

	l = 1;
	r = INF;
	while  (l <= r) {
		m = (l + r) / 2;
		if (check(m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (l >= INF)
		cout << "-1\n";
	else
		cout << l << endl;

	return 0;
}
