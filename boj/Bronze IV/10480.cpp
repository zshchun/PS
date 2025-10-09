#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> j;
		k = j;
		if (j < 0) k = -k;
		if (k % 2 == 1)
			cout << j << " is odd\n";
		else
			cout << j << " is even\n";
	}
	return 0;
}
