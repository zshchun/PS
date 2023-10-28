#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string ch[5][10] = {{" - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - "},
		    {"| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |"},
		    {"   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - "},
		    {"| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |"},
		    {" - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " - ", " - "} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, s;
	string n;
	cin >> s >> n;
	vector<int> a;
	for (char ch: n)
		a.push_back(ch-'0');

	for (i=0;i<s*2+3;i++) {
		for (k=0;k<a.size();k++) {
			if (k) cout << ' ';
			for (j=0;j<s+2;j++) {
				int r, c;
				if (i == 0) {
					r = 0;
				} else if (i == s*2+3-1) {
					r = 4;
				} else if (i < s+1) {
					r = 1;
				} else if (i == s+1) {
					r = 2;
				} else {
					r = 3;
				}

				if (j == 0) {
					c = 0;
				} else if (j == s+2-1) {
					c = 2;
				} else {
					c = 1;
				}
				cout << ch[r][a[k]][c];
			}
		}
		cout << "\n";
	}

	return 0;
}
