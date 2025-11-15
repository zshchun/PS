#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, n, ans = 0;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++) {
		ans += stol(s);
		s = s.back() + s.substr(0, s.size()-1);;
	}
	cout << ans << endl;

	return 0;
}
