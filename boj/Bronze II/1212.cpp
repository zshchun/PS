#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bool first = true;
	int x;
	string s, t;
	cin >> s;
	for (char &c : s) {
		if (c == '0') {
			x = 0;
		} else if (c == '1') {
			x = 1;
		} else if (c == '2') {
			x = 10;
		} else if (c == '3') {
			x = 11;
		} else if (c == '4') {
			x = 100;
		} else if (c == '5') {
			x = 101;
		} else if (c == '6') {
			x = 110;
		} else if (c == '7') {
			x = 111;
		}
		if (first && x == 0) continue;
		if (first) {
			cout << x;
			first = false;
		} else {
			cout << setw(3) << setfill('0') << x;
		}
	}
	if (first) cout << "0\n";
	return 0;
}
