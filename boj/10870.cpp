#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin>>n;
	int d[21];
	d[0] = 0;
	d[1] = 1;
	for (i=2;i<=n;i++) {
		d[i] = d[i-1] + d[i-2];
	}
	cout<<d[n]<<"\n";

	return 0;
}
