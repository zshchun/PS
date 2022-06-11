#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, t, n, v, j;
	string s;
	char c;
	cin >> t;
	deque<int> a;
	for (j=0;j<t;j++) {
		a.clear();
		cin >> s >> n;
		cin >> c;
		for (i=0;i<n;i++) {
			if (i > 0) cin >> c;
			cin >> v;
			a.push_back(v);
		}
		cin >> c;
		int d = 0;
		bool error = false;
		for (i=0;i<s.size();i++) {
			if (s[i] == 'R')
				d = !d;
			else if (s[i] == 'D') {
				if (a.empty()) {
					error = true;
					break;
				}
				if (d)
					a.pop_back();
				else
					a.pop_front();
			}
		}
		if (error)
			cout << "error\n";
		else {
			cout << "[";
			if (d) {
				for (i=a.size()-1;i>=0;i--) {
					if (i<a.size()-1) cout << ',';
					cout << a[i];
				}
			} else {
				for (i=0;i<a.size();i++) {
					if (i > 0) cout << ',';
					cout << a[i];
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}
