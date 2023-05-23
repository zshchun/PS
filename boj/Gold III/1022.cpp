#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll m[101][101];
ll dy[4] = {-1, 0, 1, 0};
ll dx[4] = {0, -1, 0, 1};
ll dd[4] = {-1, 0, 0, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, x, y, ny, nx;
	ll r1, c1, r2, c2;
	ll idx = 1;
	idx = 1;
	x = 0;
	y = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	for (i=0;i<=10000;i+=2) {
		for (k=0;k<4;k++) {
			ny = dy[k];
			nx = dx[k];
			for (j=0;j<i+dd[k];j++) {
				if (y >= r1 && y <= r2 && x >= c1 && x <= c2) {
					m[y-r1][x-c1] = idx;
				}
				y += ny;
				x += nx;
				idx++;
			}
		}
	}

	ny = r2 - r1;
	nx = c2 - c1;
	ll mx = max({m[0][0], m[ny][nx], m[ny][0], m[0][nx]});
	ll length = 0;

	while (mx) {
		mx /= 10;
		length++;
	}

	for (i=0;i<=ny;i++) {
		for (j=0;j<=nx;j++) {
			cout << setw(length) << m[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
