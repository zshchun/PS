#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, t, a, b;
	cin >> t;
	for (i=1;i<=t;i++) {
		cin >> a >> b;
		cout << "Scenario #" << i << ":\n";
		cout << (a + b) * (b - a + 1) / 2 << endl << endl;
	}
	return 0;
}
