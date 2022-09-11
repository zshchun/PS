#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string c;
	int n, i, a;
	vector<int> r, s;

	cin >> n;
	for (i=0;i<n;i++) {
		cin >> c;
		if (c == "push") {
			cin >> a;
			s.push_back(a);
		}  else if (c == "pop") {
			if (s.size() > 0) {
				a = s.back();
				r.push_back(a);
				s.pop_back();
			} else {
				r.push_back(-1);
			}
		}  else if (c == "size") {
			r.push_back(s.size());
		}  else if (c == "empty") {
			r.push_back(s.empty());
		}  else if (c == "top") {
			if (s.size() > 0) {
				r.push_back(s.back());
			} else {
				r.push_back(-1);
			}
		}
	}
	for (i=0;i<r.size();i++) {
		cout << r[i] << "\n";
	}
	return 0;
}
