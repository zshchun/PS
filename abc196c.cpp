#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	ll a, b;
	cin >> s;
//	if (s.size() % 2 != 0) {
//		cout << "0\n";
//		return 0;
//	}
	if (s.size() <= 1) {
		cout << "0\n";
		return 0;
	} else if (s.size() % 2 == 1) {
		int n = s.size() / 2;
		int x=1;
		while (n--) {
			x *= 10;
		}
		cout << x-1 <<"\n";
		return 0;
	}
	a = stoll(s.substr(0, s.size()/2));
	b = stoll(s.substr(s.size()/2));
//	cout << a << "\n";
//	cout << b << "\n";
	if (b >= a) {
		cout << a << "\n";
	} else {
		cout << a - 1 << "\n";
	}

//	if (b == 0) {
//		b = a - 1;
//	}
//	cout << min(b, a) << "\n";

	return 0;
}
