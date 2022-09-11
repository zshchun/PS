#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i, x, diff, c, last;
	bool flag;
	cin >> n;
	c = 0;
	for (i=1;i<=n;i++) {
		flag = true;
		last = i % 10;
		diff = ((i/10)%10) - last;
		for (x=i/10;x;x/=10) {
			if (diff != ((x%10) - last)) {
				flag = false;
				break;
			}
			last = x % 10;
		}
		if (flag) {
			c++;
		}
	}
	cout << c << '\n';
	return 0;
}

