#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n, i, j;
	cin>>m>>n;
	int *a = new int[n+1];
	a[0] = 0;
	a[1] = 0;
	for(i=2;i<=n;i++) {
		a[i] = 1;
	}
	for(i=2;i<=n;i++) {
		if (a[i] == 0)
			continue;
		for(j=i+i;j<=n;j+=i) {
			a[j] = 0;
		}
		if (i >= m)
			cout << i << '\n';
	}
	return 0;
}
