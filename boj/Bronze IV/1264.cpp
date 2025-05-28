#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (1) {
		int ans = 0;
		getline(cin, s);
		if (s == "#")
			break;
		for (char &c : s) {
			c |= 0x20;
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
