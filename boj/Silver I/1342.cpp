#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll i, ans = 0;

	sort(s.begin(), s.end());

	do {
		bool found = true;
		for (i=1;i<s.size();i++) {
			if (s[i-1] == s[i]) {
				found = false;
				break;
			}
		}
		if (found)
			ans++;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans << endl;

	return 0;
}
