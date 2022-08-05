#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, b, cnt, p;
	cin >> T;
	string s;
	bool one, valid;
	while (T--) {
		cin >> s;
		one = false;
		valid = true;
		cnt = 0;
		p = 0;
		for (i=0;i<s.size();i++) {
			b = s[i]-'0';
			if (p == b) {
				cnt++;
			} else {
				cnt = 1;
			}
			if (b && !one && cnt >= 2) one = true;
			if (one && !b && cnt >= 2) {
				valid = false;
				break;
			}
			p = b;
		}
		if (valid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
