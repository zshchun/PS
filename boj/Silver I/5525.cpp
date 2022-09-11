#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, l, f=0, v=0, ans=0;
	string s;
	cin >> n >> l >> s;
	for (i=0;i<l;i++) {
		if (s[i] == 'O')
			v = 1;
		else if (s[i] == 'I')
			v = 0;
		if (f % 2 == v)
			f++;
		else {
			if (v == 0)
				f = 1;
			else
				f = 0;
		}
		if (f >= 3 && f %2 == 1 && f >= n*2+1) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
