#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, h, m, x, ans = 0;
	char ch;
	ll tm[3];
	for (i=0;i<3;i++) {
		cin >> h >> ch >> m;
		tm[i] = h * 60 + m;
	}

	set<string> e;
	string s;
	while (cin >> h) {
		cin >> ch >> m >> s;
		x = h * 60 + m;
		if (x <= tm[0]) {
			e.insert(s);
		} else if (x >= tm[1] && x <= tm[2]) {
			if (e.count(s)) {
				e.erase(s);
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
