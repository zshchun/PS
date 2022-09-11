i#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, x, y;
	cin >> n;
	vector<pair<int, int>> xy;
	xy.reserve(n);
	for (i=0;i<n;i++) {
		cin >> x >> y;
		xy.push_back(make_pair(x, y));
	}
	sort(xy.begin(), xy.end(), [](const auto&lhs, const auto&rhs) {
		if (lhs.first == rhs.first)
			return lhs.second < rhs.second;
		else
			return lhs.first < rhs.first;
	});
	for (i=0;i<n;i++) {
		cout << xy[i].first << " " << xy[i].second << "\n";
	}
	return 0;
}
