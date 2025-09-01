#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	cin >> i;
	if (i & 1)
		cout << "0\n";
	else if ((i / 2) & 1)
		cout << "1\n";
	else
		cout << "2\n";
	return 0;
}
