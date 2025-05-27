#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, a, b, x;
	cin >> T;
	for (i=0;i<T;i++) {
		cin >> a >> b;
		x = 1;
		for (j=0;j<b;j++)
			x = (x * a) % 10;
		if (x == 0)
			cout << "10\n";
		else
			cout << x << endl;
	}
	return 0;
}
