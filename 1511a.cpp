#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N, a[4], x;
	cin >> T;
	while(T--) {
		cin >> N;
		a[3] = a[1] = a[2] = 0;
		for (i=0;i<N;i++) {
			cin >> x;
			if (x == 3) {
				a[1]++;
//				if (a[2] <= a[1])
//					a[1]++;
//				else
//					a[2]++;
			} else {
				a[x]++;
			}
		}
		cout << a[1] << '\n';

	}
	return 0;
}
