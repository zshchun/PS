#include <bits/stdc++.h>

using namespace std;

int main() {
	int y;
	cin >> y;
	if (y && (((y & 3) == 0 && (y % 100) != 0) || (y % 400) == 0)) {
		cout << "1\n";
	} else {
		cout << "0\n";
	}
	return 0;
}

