#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

bool is_number(string &s) {
	if (s.empty())
		return false;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (!isdigit(*it))
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b, c;
	ll ans;
	cin >> a >> b >> c;
	if (is_number(a)) {
		ans = stoi(a) + 3;
	} else if (is_number(b)) {
		ans = stoi(b) + 2;
	} else {
		ans = stoi(c) + 1;
	}

	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz\n";
	} else if (ans % 3 == 0) {
		cout << "Fizz\n";
	} else if (ans % 5 == 0) {
		cout << "Buzz\n";
	} else {
		cout << ans << endl;
	}

	return 0;
}
