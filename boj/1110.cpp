#include <bits/stdc++.h>

using namespace std;

int main() {
	int o, n, a, b, cnt = 0;
	cin >> n;
	o = n;

	do {
		a = n / 10;
		b = n % 10;
		n = b*10 + ((a+b) % 10);
		cnt++;
	} while (o != n);
	cout << cnt << "\n";

	return 0;
}
