#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pa;
ull INF = 1e18;
int main() {
	ull p1, p2, p3, nth, i, j, k, x, y, z;
	cin >> p1 >> p2 >> p3 >> nth;
	vector<ll> H;
	ull weight = 1;
	for (i=0;i<=60;i++) {
		if (i && INF/p1 > weight)
			weight *= p1;
		x = weight;
		for (j=0;j<=60;j++) {
			if (j && INF/p2 > weight)
				weight *= p2;
			y = weight;
			for (k=0;k<=60;k++) {
				if (k && INF/p3 > weight)
					weight *= p3;
				H.push_back(weight);
			}
			weight = y;
		}
		weight = x;
	}
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());
	cout << H[nth] << endl;
	return 0;
}
