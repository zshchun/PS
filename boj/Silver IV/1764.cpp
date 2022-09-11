#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i;
	string s;
	cin >> n >> m;
	vector<string> v;
	unordered_map<string, bool> h;
	h.reserve(max(n+1, m+1));
	v.reserve(max(n+1, m+1));
	for (i=0;i<n;i++) {
		cin >> s;
		h.insert(make_pair(s, 0));
	}

	for (i=0;i<m;i++) {
		cin >> s;
		if (h.count(s))
			v.push_back(s);
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (i=0;i<v.size();i++)
		cout << v[i] << "\n";

	return 0;
}
