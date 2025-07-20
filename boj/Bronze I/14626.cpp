#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x, ans = 0;
	char c;
	for (i=0;i<13;i++) {
		if (i % 2) k = 3;
		else k = 1;

		cin >> c;
		if (c == '*') x = k;
		else ans += k * (c - '0');
	}

	for (i=0;i<10;i++) {
		if ((i * x + ans) % 10 == 0) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
