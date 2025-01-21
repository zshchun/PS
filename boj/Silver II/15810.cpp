#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N, M;
vector<int> a;

ll okay(ll x) {
	ll total = 0;
	for (int &y : a) {
		total += x / y;
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, m, l, r, j;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		cin >> j;
		a.push_back(j);
	}
	l = 0;
	r = 1e12;
	while (l < r) {
		m = (l + r) / 2;
		if (okay(m) >= M) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << r << endl;
	return 0;
}
