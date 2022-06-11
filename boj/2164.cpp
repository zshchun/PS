#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, v;
	queue<int> a;
	cin >> n;
	for (i=1;i<=n;i++)
		a.push(i);
	for (i=1;a.size() > 0;i++) {
		v = a.front();
		a.pop();
		if (i%2 == 0)
			a.push(v);
	}
	cout << v << "\n";

	return 0;
}
