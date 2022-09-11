#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, i;
	cin >> a >> b;
	int aa = 0, bb = 0;
	for (i=a;i;i/=10)
		aa = (aa * 10) + (i % 10);
	for (i=b;i;i/=10)
		bb = (bb * 10) + (i % 10);
	if (aa > bb)
		cout << aa << "\n";
	else
		cout << bb << "\n";
	return 0;
}
