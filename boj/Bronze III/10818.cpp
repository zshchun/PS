#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, i, low, high, x;
	cin >> n;
	low =  1000001;
	high = -1000001;
	for (i=0;i<n;i++) {
		cin >> x;
		if (x < low) {
			low = x;
		}
		if (x > high) {
			high = x;
		}
	}
	cout << low << " " << high << "\n";
	return 0;
}
