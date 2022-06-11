#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, i;
	cin >> n;
	int *a = new int[n+1];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	for (i=3;i<=n;i++) {
		a[i] = (a[i-1] + a[i-2]) % 10007;
	}
	cout << a[n] << "\n";
	return 0;
}
