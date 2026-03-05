#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0, pos = 0;
	string s;
	cin >> s;
	for (char &c : s) {
		switch (c) {
			case 'A' ... 'C':
				ans += 3;
			break;
			case 'D' ... 'F':
				ans += 4;
			break;
			case 'G' ... 'I':
				ans += 5;
			break;
			case 'J' ... 'L':
				ans += 6;
			break;
			case 'M' ... 'O':
				ans += 7;
			break;
			case 'P' ... 'S':
				ans += 8;
			break;
			case 'T' ... 'V':
				ans += 9;
			break;
			case 'W' ... 'Z':
				ans += 10;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
