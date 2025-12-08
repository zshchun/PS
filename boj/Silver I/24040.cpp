#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, t, v;
	cin >> t;
	for (i=0;i<t;i++) {
		cin >> v;
		if ((v * 2 + 2) % 3 == 0)
			cout << "TAK\n";
		else if ((v % 2 == 0) && (v / 2 + 4 % 3 == 0))
			cout << "TAK\n";
		else if ((v % 3 == 0) && (v / 3 % 3 == 0))
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}

	return 0;
}
