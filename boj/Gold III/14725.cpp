#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, j, k;
	cin >> n;
	vector<vector<string>> s(n, vector<string>());
	string t;
	for (i=0;i<n;i++) {
		cin >> k;
		s[i].resize(k);
		for (j=0;j<k;j++) {
			cin >> s[i][j];
		}
	}
	sort(s.begin(), s.end());
//	sort(s.begin(), s.end(), [&](const auto &lhs, const auto &rhs) {
//		if (lhs.size() == rhs.size()) {
//			for (ll i=0;i<lhs.size();i++) {
//				if (lhs[i] != rhs[i])
//					return lhs[i] < rhs[i];
//			}
//		}
//		return lhs.size() < rhs.size();
//	});
	for (i=0;i<s.size();i++) {
		string prefix = "";
		bool same = true;
		for (j=0;j<s[i].size();j++) {
			if (!same || i == 0 || j >= s[i-1].size() || s[i][j] != s[i-1][j]) {
				cout << prefix << s[i][j] << endl;
				same = false;
			}
			prefix += "--";
		}
	}

	return 0;
}
