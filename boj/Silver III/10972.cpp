#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (ll i=0;i<N;i++)
		cin >> a[i];
	if (next_permutation(a.begin(), a.end())) {
		for (ll x: a)
			cout << x << ' ';
		cout << endl;
	} else {
		cout << "-1\n";
	}

	return 0;
}
