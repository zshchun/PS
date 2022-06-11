#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, s, c;
	s = 0;
	c = 0;
	while (cin >> i) {
		c++;
		if (i < 40) {
			s += 40;
		} else {
			s += i;
		}
	}
	cout << s / c << "\n";
	return 0;
}

