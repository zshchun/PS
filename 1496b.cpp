#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, k, i, j, mx, mex, c;
	cin>>T;
	while (T--) {
		cin >> n >> k;
		for(i=0;i<n;i++)
			cin >> a[i];
		sort(a, a+n);
		mx = a[n-1];
		c = 1;
		mex = -1;
		j = 0;
		if (a[0] != 0) mex = 0;
		else {
			for(i=1;i<n;i++)
				if (a[i] - a[i-1] > 1)
					mex = a[i-1]+1;
		}
		for(i=1;i<n;i++) {
			if (a[i] - a[i-1] > 0)
				c++;
		}
		if (mex == -1) {
			cout << n + k << "\n";
			continue;
		}
		j = (mx+mex+1)/2;
		for(i=0;i<n;i++) {
			if (j == a[i])
				break;
		}
		if (k != 0 && i==n) c++;
		cout << c << "\n";
	}
	return 0;
}
