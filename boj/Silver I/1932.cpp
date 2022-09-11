#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, j, l, p, o, n1, n2, h;
	cin >> t;
	int *a = new int[125250*4];
	for(i=1,h=0,l=0,p=9999;i<=t;i++) {
		for(j=0;j<i;j++) {
			cin >> a[l+j];
			o = l-i+j;
			if (p <= o && o < l)
				n1 = a[o];
			else
				n1 = 0;
			o++;
			if (p <= o && o < l)
				n2 = a[o];
			else
				n2 = 0;
			a[l+j] += max(n1, n2);
			if (a[l+j] > h)
				h = a[l+j];
		}
		p = l;
		l += i;
	}
	cout << h << "\n";

	return 0;

}
