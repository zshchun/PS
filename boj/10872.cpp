#include <iostream>
using namespace std;
int main() {
	long sum = 1;
	int i, v;
	cin >> v;
	for (i=2;i<=v;i++) {
		sum *= i;
	}
	cout << sum << endl;

	return 0;
}
