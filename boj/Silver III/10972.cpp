#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll N, i;
	cin >> N;
	bool ans = false;

	vector<ll> a(N);
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	next_permutation(a.begin(), a.end());
	for (i=1;i<N;i++) {
		if (a[i-1] > a[i]) {
			ans = true;
			break;
		}
	}

	if (ans) {
		for (ll x: a) {
			cout << x << ' ';
		}
		cout << endl;
	} else {
		cout << "-1\n";
	}
	return 0;
}
