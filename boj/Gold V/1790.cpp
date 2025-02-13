#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, digit = 1, l = 10, j = 0, ans = -1, n, k;
	cin >> n >> k;
	for (i=1;i<=n;i++) {
		if (i == l) {
			l *= 10;
			digit++;
		}
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
