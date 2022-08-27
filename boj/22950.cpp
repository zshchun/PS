#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll m, k, n = 0;
	int i;
	char c;
	cin >> m;
	vector<bool> bits(m);
	for (i=1;i<=m;i++) {
		cin >> c;
		bits[m-i] = (c-'0');
	}
	cin >> k;
	for (i=0;i<k && i<m;i++) {
		if (bits[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
