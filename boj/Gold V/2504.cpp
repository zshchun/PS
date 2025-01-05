#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define SQUARE -1
#define CIRCLE -2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0, i, a;
	string s;
	cin >> s;
	vector<int> x;
	for (char c : s) {
		if (c == ']' || c == ')') {
			i = 0;
			while (!x.empty() && x.back() > 0) {
				i += x.back();
				x.pop_back();
			}
			if (x.size() > 0 &&
			    ((x.back() == SQUARE && c == ']') ||
			     (x.back() == CIRCLE && c == ')'))) {
				x.pop_back();
				if (c == ')') {
					if (i) i *= 2;
					else i = 2;
				} else if (c == ']') {
					if (i) i *= 3;
					else i = 3;
				}
			} else {
				x.push_back(-INF);
				break;
			}

			x.push_back(i);
		} else if (c == '(') {
			x.push_back(CIRCLE);
		} else if (c == '[') {
			x.push_back(SQUARE);
		}
	}
	for (int j : x) {
		if (j > 0) {
			ans += j;
		} else {
			ans = 0;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
