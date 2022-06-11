#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, v;
	cin >> n;
	unordered_map<int, int> a;
	for (i=0;i<n;i++) {
		cin >> v;
		a[v]++;
	}
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (i) cout << " ";
		cout << a[v];
	}
	cout << "\n";
	return 0;
}
