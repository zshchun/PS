#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, k, i;
	string s;
	cin >> T;
	while (T--) {
		cin >> n>>k;
		cin >> s;
		if (k == 0) {
			cout << "YES\n";
			continue;
		}
		if (k*2 >= n) {
			cout << "NO\n";
			continue;
		}
		for (i=0;i<k;i++) {
			if (s[i] != s[n-1-i])
				break;
		}
		if (i == k)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}
