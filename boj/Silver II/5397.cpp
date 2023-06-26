#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		vector<char> v;
		deque<char> q;
		for (char ch : s) {
			if (ch == '<') {
				if (!v.empty()) {
					q.push_front(v.back());
					v.pop_back();
				}
			} else if (ch == '>') {
				if (!q.empty()) {
					v.push_back(q.front());
					q.pop_front();
				}
			} else if (ch == '-') {
				if (!v.empty()) {
					v.pop_back();
				}
			} else {
				v.push_back(ch);
			}
		}
		for (char ch : v) cout << ch;
		for (char ch : q) cout << ch;
		cout << endl;

	}

	return 0;
}
