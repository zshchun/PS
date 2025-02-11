#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int x, y;

int convert_xy(int d, int j) {
	if (d == 1) {
		d = j;
	} else if (d == 2) {
		d = x + y + (x - j);
	} else if (d == 3) {
		d = x + y + x + (y - j);
	} else if (d == 4) {
		d = x + j;
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k, d, i, j, mx, sx, sy, ans = 0;
	cin >> x >> y >> k;
	vector<int> v;
	mx = (x + y) * 2;

	for (i=0;i<k;i++) {
		cin >> d >> j;
		v.push_back(convert_xy(d, j));
	}
	cin >> sx >> sy;
	k = convert_xy(sx, sy);

	for (int &z : v) {
		j = abs(z-k);
		if (j <= mx / 2)
			ans += j;
		else
			ans += mx - j;
	}
	cout << ans << endl;

	return 0;
}
