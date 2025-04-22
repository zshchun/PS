#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j;
	cin >> T;
	while (T--) {
		cin >> i;
		for (j=0;j<32;j++) {
			if (i & (1 << j))
				cout << j << ' ';
		}
		cout << endl;
	}
	return 0;
}
