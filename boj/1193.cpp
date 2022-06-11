#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, i, m, c, d;
	cin>>x;
	m=1;
	c=1;

	for (i=1;i<x;i++) {
		if (c==1) {
			m++;
			d = 1;
			i++;
		} else if (m==1) {
			c++;
			d = -1;
			i++;
		}
		if (i<x) {
			m -= d;
			c += d;
		}
	}
	cout << c << "/" << m << "\n";
	
	return 0;
}
