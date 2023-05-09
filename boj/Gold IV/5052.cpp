#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll t, n, i, j;
	cin >> t;
	while (t--) {
		bool ans = true;
		cin >> n;
		vector<string> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), greater<string>());

		unordered_set<string> s;
		for (i=0;i<n && ans;i++) {
			if (s.count(a[i]) > 0) {
				ans = false;
			}

			s.insert(a[i]);
			for (j=1;j<(ll)a[i].size();j++) {
				s.insert(a[i].substr(0, j));
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
