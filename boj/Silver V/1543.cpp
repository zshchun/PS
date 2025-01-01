#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pos = 0, ans = 0;
	string a;
	string b;

	getline(cin, a);
	getline(cin, b);

	while (pos < a.size()) {
		if (a.substr(pos, b.size()) == b) {
			ans++;
			pos += b.size();
		} else {
			pos++;
		}
	}
	cout << ans << endl;

	return 0;
}
