#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q, i, n, c = 0;
	cin >>n>>q;
	int a[10];
	for(i=0;i<n;i++)
		cin >> a[i];
	
	for(i=n-1;i>=0;i--) {
		while (q >= a[i]) {
			q -= a[i];
			c++;
		}
	}
	cout << c <<"\n";
	return 0;
}
