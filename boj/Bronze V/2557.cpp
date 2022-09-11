#include <bits/stdc++.h>

using namespace std;

int main() {
	int aa[10];
	int a, b, c, s, i;

	cin >> a >> b >> c;
	s = a * b * c;
	for (i=0;i<10;i++)
		aa[i] = 0;

	while (s) {
		aa[(s%10)]++;
		s /= 10;
	}
	for (i=0;i<10;i++)
		cout << aa[i] << "\n";
	return 0;
}


