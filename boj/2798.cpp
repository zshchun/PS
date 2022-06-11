#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, m, i, j, k, s = 0, q;
	int a[100];
	cin>>t>>m;
	for (i=0;i<t;i++)
		cin>>a[i];
	for (i=0;i<t;i++) {
		for (j=0;j<t;j++) {
			if (j==i) continue;
			for (k=0;k<t;k++) {
				if (k==i || k==j) continue;
				q = a[i] + a[j] + a[k];
				if (q <= m && q > s)
					s = q;
			}
		}
	}
	cout << s << '\n';
	return 0;
}
