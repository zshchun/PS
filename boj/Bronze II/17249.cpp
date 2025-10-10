#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	string s;
	cin >> s;
	for (char &c : s) {
		if (c == '@') {
			ans++;
		} else if (c == '0') {
			cout << ans << ' ';
			ans = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
