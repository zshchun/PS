#include <bits/stdc++.h>
using namespace std;
int main() {
	int i, j, s;
	int a[10001];
	a[0] = 0;
	for (i=1;i<10000;i++)
		a[i] = -1;
	for (i=1;i<10000;i++) {
		s = i;
		for (j=i;j;j/=10) {
			s += j % 10;
		}
		if (s <= 10000)
			a[s] = i;
	}
	for (i=1;i<10000;i++) {
		if (a[i] == -1) {
			cout << i << '\n';
		}
	}

	return 0;
}
