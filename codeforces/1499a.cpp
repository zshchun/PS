#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, k1, k2, B, W, b, w;
	cin >> T;
	while (T--) {
		cin>>n>>k1>>k2>>W>>B;
		w = min(k1, k2);
		w += abs(k1-k2)/2;
		b = min(n-k1, n-k2);
		b += abs((n-k1)-(n-k2))/2;
//		cout << w << ":"<<b<<'\n';
		if (w >= W && b >= B)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}
