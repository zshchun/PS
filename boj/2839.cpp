#include <iostream>

using namespace std;

int main() {
	int n, i, r;
	cin >> n;
	int ret = -1;
	for (i=n/5;i>=0;i--) {
		r = n - (i * 5);
		if (r == 0) {
			ret = i;
			break;
		}
		if ((r % 3) == 0) {
			ret = i + (r / 3);
			break;
		}
	}

	cout << ret << "\n";
	return 0;
}

