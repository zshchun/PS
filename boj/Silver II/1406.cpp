#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	int N;
	char cmd, ch;
	cin >> str >> N;
	list<char> s(str.begin(), str.end());

	list<char>::iterator it = s.end();
	while (N--) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> ch;
			s.insert(it, ch);
		} else if (cmd == 'L') {
			if (it != s.begin()) 
				it--;
		} else if (cmd == 'D') {
			if (it != s.end()) 
				it++;
		} else if (cmd == 'B') {
			if (it != s.begin()) {
				it--;
				it = s.erase(it);
			}
		}
	}
	for (char c : s)
		cout << c;
	cout << endl;
	return 0;
}
