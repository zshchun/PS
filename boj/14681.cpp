#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y, r = 0;
	cin >> x >> y;
	if (x > 0 && y > 0)
		r = 1;
	else if (x < 0 && y > 0)
		r = 2;
	else if (x < 0 && y < 0)
		r = 3;
	else if (x > 0 && y < 0)
		r = 4;
	cout << r << "\n";
	return 0;
}
