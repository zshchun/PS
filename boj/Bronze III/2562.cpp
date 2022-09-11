#include <bits/stdc++.h>
using namespace std;
int main() {
	int c = 1;
	int max = 0;
	int o = 0, i;
	while (cin >> i) {
		if (i > max) {
			o = c;
			max = i;
		}
		c++;
	}
	cout << max << "\n";
	cout << o << "\n";
	return 0;
}
