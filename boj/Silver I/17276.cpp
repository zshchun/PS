#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int a[501][501];
int saved[8][251];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, i, j, x, y, d, h, cy, cx;
	cin >> T;
	while (T--) {
		cin >> n >> d;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				cin >> a[i][j];
		h = n / 2;
		for (i=0;i<8;i++) {
			y=h+dy[i]*h; x=h+dx[i]*h;
			for (j=0;j<h;j++) {
				saved[i][j] = a[y][x];
				y-=dy[i]; x-=dx[i];
			}
		}
		if (d > 0)
			d = (360 - d) / 45;
		else
			d = -d / 45;
		for (i=0;i<8;i++) {
			y=h+dy[i]*h; x=h+dx[i]*h;
			for (j=0;j<h;j++) {
				a[y][x] = saved[(i+d)%8][j];
				y-=dy[i]; x-=dx[i];
			}
		}
		for (i=0;i<n;i++) {
			for (j=0;j<n;j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}
