#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b;
	double c;
	cin >> a;
	cin >> b;
	c = a / b;

	cout << setprecision(10) << c << '\n';
	return 0;
}

