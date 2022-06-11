#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, p=0, s;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> a[p];
		if (a[p] == 0) {
			if (p > 0) p--;
		} else  {
			p++;
		}
	}
	s = accumulate(a, a+p, 0);
	cout << s << "\n";
	return 0;
}

