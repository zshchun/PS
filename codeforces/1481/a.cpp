#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, mx, my, i, j, sx, sy, dx, dy;
	string s;
	cin >> t;
	while (t--) {
		cin>>dx>>dy;
		cin>>s;
		sx = 0;
		sy = 0;
		for (char c : s) {
			if (c == 'U' && dy > sy) {
				sy++;
			} else if (c == 'D' && dy < sy) {
				sy--;
			} else if (c == 'R' && dx > sx) {
				sx++;
			} else if (c == 'L' && dx < sx) {
				sx--;
			}
		}
		if (sy == dy && sx == dx)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
