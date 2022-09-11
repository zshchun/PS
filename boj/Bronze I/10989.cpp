#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, v, j;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		a[v]++;
	}
	for (i=1;i<=10000;i++) {
		if (a[i])
			for (j=0;j<a[i];j++)
				cout << i << "\n";
	}
	return 0;
}
