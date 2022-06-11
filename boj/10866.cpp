#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, v;
	deque<int> dq;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "push_back") {
			cin >> v;
			dq.push_back(v);
		} else if (s == "push_front") {
			cin >> v;
			dq.push_front(v);
		} else if (s == "pop_front") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		} else if (s == "pop_back") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		} else if (s == "size") {
			cout << dq.size() << "\n";
		} else if (s == "empty") {
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		} else if (s == "front") {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << "\n";
		} else if (s == "back") {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << "\n";
		}
	}
	return 0;
}
