#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, w, i, v, k, mx = 0, mn = 1<<30, x, y, j;
	cin>>a>>b>>w;
	w *= 1000;

	for (i=a;i<=b;i++) {
		if (w % i == 0) {
			v = w / i;
			if (v > mx) mx = v;
			if (v < mn) mn = v;
			continue;
		}

		x = min(w, 10000) / i;
		for (j=1;j<=x;j++) {
			y = w - (i*j);
			for (k=a;k<=b;k++) {
				if (i == k) continue;
				if (y % k == 0) {
					v = (y / k) + j;
					if (v > mx) mx = v;
					if (v < mn) mn = v;
				}
			}
		}
	}
	if (!mx)
		cout << "UNSATISFIABLE\n";
	else
		cout << mn << " " << mx << "\n";

	return 0;
}
