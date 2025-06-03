#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll fib[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, v, x;
	cin >> T;
	fib[0] = 0;
	fib[1] = 1;
	for (i=2;i<=46;i++)
		fib[i] = fib[i-1] + fib[i-2];
	while (T--) {
		cin >> v;
		vector<ll> a;
		while (v) {
			auto it = upper_bound(fib, fib+45, v);
			x = *(it-1);
			v -= x;
			a.push_back(x);
		}
		reverse(a.begin(), a.end());
		for (ll &q : a)
			cout << q << ' ';
		cout << endl;
	}
	return 0;
}
