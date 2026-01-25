#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, R, d, nx, ny, x, y;
int a[301][301];
int b[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void move(int k, int &d, int &y, int &x) {
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (nx < k || ny < k || nx >= M-k || ny >= N-k)
		d = (d + 1) % 4;
	x += dx[d];
	y += dy[d];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, d, r, sy, sx, ny, nx, nd;
	cin >> N >> M >> R;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			cin >> a[i][j];

	for (k=0;k<min(N, M)/2;k++) {
		nd = d = 0;
		y = x = k;
		for (r=0;r<R;r++)
			move(k, d, y, x);
		sx = x;
		sy = y;
		nx = ny = k;
		do {
			b[ny][nx] = a[y][x];
			move(k, d, y, x);
			move(k, nd, ny, nx);
		} while (nx != k || ny != k);
	}
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
