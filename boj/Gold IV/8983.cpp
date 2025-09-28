#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll M, N, L, ans;

ll wp[100001]; // weapon

// binary search
int binary_search(ll y, ll x) {
	ll l, m, r, dist;
	l = 0;
	r = M-1;
	while (l <= r) {
		m = (l + r) / 2;
		dist = abs(wp[m] - x) + y;
		if (dist <= L)
			return 1;
		else if (wp[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, x, y;
	cin >> M >> N >> L;
	for (i=0;i<M;i++)
		cin >> wp[i];
	sort(wp, wp+M);

	for (i=0;i<N;i++) {
		cin >> x >> y;
		ans += binary_search(y, x);
	}

	cout << ans << endl;
	
	return 0;
}
