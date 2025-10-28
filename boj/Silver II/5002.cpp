#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, w, m, d;
	string s;
	stack<int> t;
	w = m = 0;
	cin >> x >> s;
	while (s.size() > 0) {
		bool found = false;
		for (int i=0;i<min(2, (int)s.size());i++) {
			if (s[i] == 'M') {
				if (abs(w - (m+1)) <= x) {
					m++;
					found = true;
					s.erase(i, 1);
					break;
				}
			} else if (s[i] == 'W') {
				if (abs(m - (w+1)) <= x) {
					w++;
					found = true;
					s.erase(i, 1);
					break;
				}
			}
		}
		if (!found) break;
	}
	cout << m + w << endl;

	return 0;
}
