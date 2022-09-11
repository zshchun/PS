#include <bits/stdc++.h>
using namespace std;

int c0[41], c1[41];
void fibonacci(int n) {
	if (n == 0) {
		c0[n]++;
	} else if (n == 1) {
		c1[n]++;
	} else {
		c0[n] += c0[n-1] + c0[n-2];
		c1[n] += c1[n-1] + c1[n-2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int nr, i, n;
	cin >> nr;
	for (i=0;i<=40;i++) {
		c0[i] = 0;
		c1[i] = 0;
		fibonacci(i);
	}
	for (i=0;i<nr;i++) {
		cin >> n;
		cout << c0[n] << " " << c1[n] << "\n";
	}
	return 0;
}

