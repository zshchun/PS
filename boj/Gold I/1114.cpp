#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll L, K, C, ans, low;
vector<ll> a;

bool is_possible(ll x) {
	ll sum = 0, cnt = 0, prev = L;
	for (int i=a.size()-2;i>=0;i--) {
		if (prev - a[i] > x) {
			cnt++;
			prev = a[i+1];
			if (prev - a[i] > x)
				return false;
		}
	}
	if (cnt < C)
		low = a[1];
	else
		low = prev;
	return cnt <= C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, l, r, m, c;
	cin >> L >> K >> C;
	a.resize(K);
	for (i=0;i<K;i++)
		cin >> a[i];

	a.push_back(0);
	a.push_back(L);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	// parametric search, binary search
	l = 0;
	r = L;
	while (l <= r) {
		m = (l + r) / 2;
		if (is_possible(m))
			r = m - 1;
		else
			l = m + 1;
	}

	is_possible(l);
	cout << l << ' ' << low << endl;
	return 0;
}
