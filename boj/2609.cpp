#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, G, L, r;
	cin>>a>>b;
	L = a * b;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	G = a;
	L /= G;
	cout << G << "\n";
	cout << L << "\n";

	return 0;
}
