#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, j;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> j;
		if (j % 2 == 0)
			cout << j << " is even\n";
		else
			cout << j << " is odd\n";
	}
	return 0;
}
