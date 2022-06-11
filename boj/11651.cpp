#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(pair<int,int> &lhs, pair<int,int> &rhs) {
	if (lhs.second == rhs.second)
		return lhs.first < rhs.first;
	else
		return lhs.second < rhs.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int,int>> xy;
	int x, y, n, i;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> x >> y;
		xy.push_back(pair<int,int>(x, y));
	}
	sort(xy.begin(), xy.end(), compare);
	for (i=0;i<n;i++)
		cout << xy[i].first << " " << xy[i].second << "\n";
	return 0;
}
