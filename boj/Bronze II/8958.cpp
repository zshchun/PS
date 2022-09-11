#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i, c;
	char l[81], *p;

	cin >> n;
	cin.getline(l, 81);
	int *sum = new int[n];
	for (i=0;i<n;i++) {
		cin.getline(l, 81);
		p = l;
		c = 0;
		sum[i] = 0;
		while (*p) {
			if (*p == 'O') {
				c++;
				sum[i] += c;
			} else {
				c = 0;
			}
			p++;
		}
	}
	for (i=0;i<n;i++) {
		cout << sum[i] << "\n";
	}
	return 0;
}
