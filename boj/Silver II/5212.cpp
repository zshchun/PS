#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int R, C;
int a[11][11];
int b[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool is_sink(int x, int y) {
	int nx, ny, i, island = 0;
	if (!a[x][y])
		return false;

	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
		if (a[nx][ny])
			island++;
	}
	if (island <= 1)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> R >> C;

	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> c;
			if (c == 'X') {
				a[i][j] = 1;
				b[i][j] = 1;
			}
		}
	}

	int r1 = INF;
	int c1 = INF;
	int r2 = 0;
	int c2 = 0;

	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (is_sink(i, j))
				b[i][j] = 0;
			if (b[i][j]) {
				r1 = min(r1, i);
				c1 = min(c1, j);
				r2 = max(r2, i);
				c2 = max(c2, j);
			}
		}
	}

	for (i=r1;i<=r2;i++) {
		for (j=c1;j<=c2;j++) {
			if (b[i][j])
				cout << 'X';
			else
				cout << '.';
		}
		cout << endl;
	}

	return 0;
}
