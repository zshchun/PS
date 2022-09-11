#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, i, a, s = 0;
	char buf[10];

	cin >> n;
	cin.getline(buf, 10);

	for (i=0;i<n;i++) {
		s += getchar() - '0';
		a /= 10;
	}
	cout << s << "\n";

	return 0;
}



