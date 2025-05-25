#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, m, sz, ans;
	string s;
	cin >> T;
	for (j=0;j<T;j++) {
		ans = true;
		cin >> s;
		sz = s.size();
		while (sz > 1 && ans) {
			m = sz / 2;
			for (i=0;i<m;i++) {
				if (s[i] == s[sz-1-i]) {
					ans = false;
					break;
				}
			}
			sz = m;
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}
