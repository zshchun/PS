#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k, i, j, nr=0;
	int a[1001];
	int r[1001];
	cin>>t;
	while(t--) {
		cin >> n >> k;
		nr = 0;
		for(i=k+1;i<=n;i++) {
			r[nr++] = i;
		}
		for(i=1;i<k;i++) a[i] = 1;
		for(i=1;i<k;i++) {
			for(j=i;j<k;j++) {
				if (i == j) continue;
				if (i+j == k)
					a[i] = 0;
			}
		}
		for(i=1;i<k;i++)
			if (a[i])
				r[nr++] = i;
		cout << nr << "\n";
		for(i=0;i<nr;i++) {
			if (i) cout << " ";
			cout << r[i];
		}
		if (nr > 0) cout << "\n";
	}
	return 0;
}
