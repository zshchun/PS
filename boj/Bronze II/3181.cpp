#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

set<string> blacklist = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili",};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, ans;
	while (cin >> s) {
		if (ans.size() == 0) {
			ans += s[0] & ~0x20;
		} else {
			if (blacklist.find(s) == blacklist.end())
				ans += s[0] & ~0x20;
		}
	}
	cout << ans << endl;
	return 0;
}
