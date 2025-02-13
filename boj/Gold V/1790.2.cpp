#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i=1, digit = 1, j = 0, ans = -1, n, k, x;
	cin >> n >> k;
	while (n >= i * 10) {
		x = digit * (i * 10 - i);
		if (j + x >= k) break;
		j += x;
		i *= 10;
		digit++;
	}

	for (;i<=n;i++) {
		if (j+digit >= k) {
			vector<int> a;
			while (i) {
				a.push_back(i % 10);
				i /= 10;
			}
			reverse(a.begin(), a.end());
			ans = a[k-j-1];
			break;
		}
		j += digit;
	}
	cout << ans << endl;
	return 0;
}
