#include <iostream>

using namespace std;

int main() {
	int n, i, s = 0;
	cin >> n;
	for (i=1;i<=n;i++) {
		s += i;
	}
	cout << s << '\n';
	
	return 0;
}
