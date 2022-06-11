#include <iostream>

using namespace std;

int main() {
	int n, x, i, t;
	char buf[80];
	cin >> n >> x;
	cin.getline(buf, 80);
	for (i=0;i<n;i++) {
		cin >> t;
		if (t < x) {
			cout << t << " ";
		}
	}
	cout << "\n";
	return 0;
}

