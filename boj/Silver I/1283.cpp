#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int used[128];

void paren(string &s, int pos) {
	for (int i=0;i<s.size();i++) {
		if (i == pos)
			cout << '[' << s[i] << ']';
		else
			cout << s[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	string line, t;
	getline(cin, line);
	while (getline(cin, line)) {
		istringstream is(line);
		vector<string> s;
		int found = -1;
		while (getline(is, t, ' '))
			s.push_back(t);

		for (i=0;i<s.size();i++) {
			if (!used[s[i][0]|0x20]) {
				used[s[i][0]|0x20] = 1;
				found = i;
				break;
			}
		}
		if (found >= 0) {
			for (i=0;i<s.size();i++) {
				if (i == found)
					paren(s[i], 0);
				else
					cout << s[i];
				cout << ' ';
			}
		} else {
			bool done = false;
			for (i=0;i<s.size();i++) {
				for (j=0;j<s[i].size();j++) {
					if (!done && !used[s[i][j]|0x20]) {
						used[s[i][j]|0x20] = 1;
						done = true;
						cout << '[' << s[i][j] << ']';
					} else {
						cout << s[i][j];
					}
				}
				cout << ' ';
			}
		}
		
		cout << endl;

	}

	return 0;
}
