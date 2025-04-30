#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, C, mn_y, mx_y, mn_x, mx_x, y, x;
int a[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	y = x = mn_y = mx_y = mn_x = mx_x = 50;
	a[y][x] = 1;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> c;
		if (c == 'F') {
			y += dy[C];
			x += dx[C];
			mn_y = min(mn_y, y);
			mx_y = max(mx_y, y);
			mn_x = min(mn_x, x);
			mx_x = max(mx_x, x);
			a[y][x] = 1;
		} else if (c == 'L') {
			C = (C + 3) % 4;
		} else if (c == 'R') {
			C = (C + 1) % 4;
		}
	}
	for (i=mn_y;i<=mx_y;i++) {
		for (j=mn_x;j<=mx_x;j++) {
			if (a[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << endl;
	}
	return 0;
}
