#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, left, right, ans = 0;
	cin >> n;
	left = min(n, 5);
	right = max(n-5, 0);
	while (left >= right) {
		left--;
		right++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
