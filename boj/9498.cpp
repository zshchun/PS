#include <iostream>

using namespace std;

int main() {
	int s;
	cin >> s;
	if (s >= 90 && s <= 100) {
		cout << "A\n";
	} else if (s >= 80 && s <= 89) {
		cout << "B\n";
	} else if (s >= 70 && s <= 79) {
		cout << "C\n";
	} else if (s >= 60 && s <= 69) {
		cout << "D\n";
	} else {
		cout << "F\n";
	}
	return 0;
}

