#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
enum MODE {
	SPACE,
	WORD,
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin, s);
	ll i, ans=0;
	enum MODE mode = SPACE;
	for (i=0;i<s.size();i++) {
		if (s[i] == ' ') {
			mode = SPACE;
		} else {
			if (mode == SPACE) {
				mode = WORD;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
