#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, ans;
	while (1) {
		cin >> n;
		ans = 1;
		if (n == 0) break;
		while (n) {
			i = n % 10;
			if (i == 1)
				ans += 2 + 1;
			else if (i == 0)
				ans += 4 + 1;
			else
				ans += 3 + 1;
			n /= 10;
		}
		cout << ans << endl;
	}

	return 0;
}
