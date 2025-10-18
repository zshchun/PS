#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, v, cnt, ans = 0;
	cin >> n;
	// stack
	vector<pa> s;
	for (i=0;i<n;i++) {
		cin >> v;
		cnt = 1;
		while (!s.empty() && s.back().first < v) {
			ans += s.back().second;
			s.pop_back();
		}

		if (!s.empty()) {
			if (s.back().first == v) {
				ans += s.back().second;
				cnt = s.back().second + 1;
				s.pop_back();
				if (!s.empty()) ans++;
			} else {
				ans++;
			}
		}
		s.push_back(pa(v, cnt));
	}
	cout << ans << endl;
	return 0;
}
