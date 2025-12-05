#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	while (cin >> i) {
		if (i == 0) break;
		if (i > 1000000 && i <= 5000000)
			cout << i / 10 * 9 << endl;
		else if (i > 5000000)
			cout << i / 10 * 8 << endl;
		else
			cout << i << endl;
	}
	return 0;
}
