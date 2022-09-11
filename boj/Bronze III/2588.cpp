#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, s;
	cin >> a >> b;
	s = a * b;
	cout << a * (b % 10) << "\n";
	b /= 10;
	cout << a * (b % 10) << "\n";
	b /= 10;
	cout << a * (b % 10) << "\n";
	cout << s << "\n";
	return 0;
}
