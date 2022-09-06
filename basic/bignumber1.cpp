#include <bits/stdc++.h>
using namespace std;
int a[2000];
int multiply(int x, int len) {
	int carry = 0, i;
	for (i=0;i<len;i++) {
		int y = a[i] * x + carry;
		a[i] = y % 10;
		carry = y / 10;
	}
	while (carry) {
		a[i++] = carry % 10;
		carry /= 10;
	}
	return i;
}
int factorial(int x) {
	int i, len = 1;
	a[0] = 1;
	for (i=2;i<=x;i++)
		len = multiply(i, len);
	return len;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, i, len, ans=0;
	cin >> x;
	len = factorial(x);
	for (i=0;i<len;i++) {
		if (a[i] != 0) break;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
