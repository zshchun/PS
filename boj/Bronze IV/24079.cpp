#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	if (x + y <= z)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}
