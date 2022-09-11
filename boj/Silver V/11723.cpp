#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, v;
	set<int> e;
	set<int> all = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		if (s == "add") {
			cin >> v;
			e.insert(v);
		} else if (s == "check") {
			cin >> v;
			if (e.count(v))
				cout << "1\n";
			else
				cout << "0\n";
		} else if (s == "remove") {
			cin >> v;
			if (e.count(v))
				e.erase(v);
		} else if (s == "toggle") {
			cin >> v;
			if (e.count(v))
				e.erase(v);
			else
				e.insert(v);
		} else if (s == "all") {
			e = all;
		} else if (s == "empty") {
			e.clear();
		}
	}
	return 0;
}

