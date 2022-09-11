#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<string> name;
	unordered_map<string, int> s;
	int n, m, i, x;
	string a;
	cin >> n >> m;
	name.reserve(n);
	s.reserve(n);
	for (i=0;i<n;i++) {
		cin >> a;
		s.insert(make_pair(a, i+1));
		name.push_back(a);
	}
	for (i=0;i<m;i++) {
		cin >> a;
		if (a[0] >= '0' && a[0] <= '9') {
			x = stoi(a);
			cout << name[x-1] << "\n";
		} else {
			cout << s.at(a) << "\n";
		}

	}
	return 0;
}
