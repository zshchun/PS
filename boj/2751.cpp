#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	int *a = new int[n];
	for(i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for(i=0;i<n;i++) {
		cout << a[i] <<"\n";
	}
	return 0;
}
