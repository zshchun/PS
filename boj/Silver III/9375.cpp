#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, i;
	cin >> T;
	unordered_map<string,int> n, c;
	string s;
	while (T--) {
		cin >> N;
		n.clear();
		c.clear();
		for (i=0;i<N;i++) {
			cin >> s;
			if (n.count(s))
				n[s]++;
			else
				n.insert(make_pair(s, 1));
			cin >> s;
			if (c.count(s))
				c[s]++;
			else
				c.insert(make_pair(s, 1));
		}
		int ans = 1;
		for (unordered_map<string,int>::iterator it=c.begin();it!=c.end();++it) {
			ans *= it->second + 1;
		}

		cout << ans-1 << '\n';
	}
	return 0;
}

