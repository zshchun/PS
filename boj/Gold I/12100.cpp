#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[21][21];
bool merged[21][21];
int n, ans;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void roll(int (&b)[21][21], int sy, int ey, int stepy, int sx, int ex, int stepx, int d) {
	int y, x, nx, ny, px, py;
	for (y = sy; y != ey; y += stepy) {
		for (x = sx; x != ex; x += stepx) {
			if (!b[y][x]) continue;
			py = ny = y;
			px = nx = x;
			nx += dx[d];
			ny += dy[d];
			while (nx >= 0 && ny >= 0 && ny < n && nx < n && !b[ny][nx]) {
				swap(b[py][px], b[ny][nx]);
				py = ny;
				px = nx;
				nx += dx[d];
				ny += dy[d];
			}
			if (nx >= 0 && ny >= 0 && ny < n && nx < n && b[ny][nx] && b[py][px] == b[ny][nx] && !merged[ny][nx]) {
				merged[ny][nx] = 1;
				b[ny][nx] *= 2;
				b[py][px] = 0;
				ans = max(ans, b[ny][nx]);
			}
		}
	}
}

void dfs(int c, int a[21][21]) {
	int i, j, k, x, y;
	int b[21][21];
	for (i=0;i<4;i++) {
		memcpy(b, a, sizeof(b));
		memset(merged, 0, sizeof(merged));
		if (i == 0)
			roll(b, 0, n, 1, n-1, -1, -1, i);
		else if (i == 2)
			roll(b, n-1, -1, -1, 0, n, 1, i);
		else
			roll(b, 0, n, 1, 0, n, 1, i);
		if (c < 4)
			dfs(c+1, b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) {
			cin >> a[i][j];
			ans = max(ans, a[i][j]);
		}
	dfs(0, a);

	cout << ans << endl;

	return 0;
}
