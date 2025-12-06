#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	string s;
	cin.ignore(2, '\n');
	for (i=0;i<n;i++) {
		getline(cin, s);
		set<char> al;
		for (char &c : s) {
			c |= 0x20;
			if (c >= 'a' && c <= 'z')
				al.insert(c);
		}
		if (al.size() == 26)
			cout << "pangram\n";
		else {
			cout << "missing ";
			for (char c='a';c<='z';c++)
				if (al.count(c) == 0)
					cout << c;
			cout << endl;
		}
	}
	return 0;
}
