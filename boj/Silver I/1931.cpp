#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, f, s, ans=0;
	cin >> n;
	vector<pair<int,int>> t;
	t.reserve(n+1);
	for (i=0;i<n;i++) {
		cin >> f >> s;
		t.push_back(pair<int,int>(f, s));
	}
	sort(t.begin(), t.end(), [](const auto &lhs, const auto &rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		else
			return lhs.second < rhs.second;
	});
	int e = -1;
	for (i=0;i<n;i++) {
		if (e <= t[i].first) {
			e = t[i].second;
			ans++;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
