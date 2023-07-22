#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, i, j, k, ans = -1;
	cin >> x >> y;
	vector<int> a;
//	if (y < x) {
//		cout << "-1\n";
//		return 0;
//	}
	while (x) {
		i = x % 10;
		a.push_back(i);
		x /= 10;
	}
	sort(a.begin(), a.end());

	while (next_permutation(a.begin(), a.end())) {
		k = 0;
		if (a[0] == 0)
			continue;
		for (int j : a) {
			k = k * 10 + j;
		}
		if (k < y)
			ans = k;
		else
			break;
	}
	cout << ans << endl;

	return 0;
}
