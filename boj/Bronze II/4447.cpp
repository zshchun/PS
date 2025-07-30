#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, g, b;
	cin >> n;
	cin.ignore(80, '\n');
	for (i=0;i<n;i++) {
		string s;
		getline(cin, s);
		g = 0; b = 0;
		for (char c : s) {
			c |= 0x20;
			if (c == 'g') g++;
			else if (c == 'b') b++;

		}
		if (s.back() == '\r' || s.back() == '\n')
			s.pop_back();
		if (g == b)
			cout << s << " is NEUTRAL\n";
		else if (g > b)
			cout << s << " is GOOD\n";
		else
			cout << s << " is A BADDY\n";
	}
	return 0;
}
