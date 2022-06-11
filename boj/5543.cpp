#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d, e, x;
	cin>>a>>b>>c>>d>>e;
	x = min(a, min(b, c)) + min(d, e) - 50;
	cout << x << "\n";
	return 0;
}
