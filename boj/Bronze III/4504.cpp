#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v, n;
	cin >> n;
	while (1) {
		cin >> v;
		if (v == 0) break;
		string s;
		if (v % n != 0)
			s = "NOT ";
		cout << v << " is " << s << "a multiple of " << n << ".\n";
	}
	return 0;
}
