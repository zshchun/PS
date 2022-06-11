#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, s = 0;
	char c;
	bool minus = false;
	while (cin >> a) {
		if (minus)
			s -= a;
		else
			s += a;
		if (cin >> c)
			if (c == '-')
				minus = true;
	}
	cout << s << '\n';
	return 0;
}
