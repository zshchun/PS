#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a[1001], b[1001], m = 1<<30, j, i;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i] >> b[i];
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if (i == j && a[j]+b[i] < m) {
				m = a[i]+b[j];
			}
			if (i != j && max(a[i],b[j]) < m) {
				m = max(a[i],b[j]);
			}
		}
	}
	cout << m << "\n";
	return 0;
}
