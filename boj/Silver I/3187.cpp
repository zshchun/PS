#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define WALL  1
#define WOLF  2
#define SHEEP 3

int R, C, w, s;
int a[250][250];
bool visited[250][250];
int ans[2];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void dfs(int y, int x) {
	int nx, ny, i;
	if (y >= R || y < 0 || x >= C || x < 0)
		return;
	if (visited[y][x])
		return;
	visited[y][x] = 1;
	if (a[y][x] == WALL)
		return;
	else if (a[y][x] == SHEEP)
		s++;
	else if (a[y][x] == WOLF)
		w++;

	for (i=0;i<4;i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		dfs(ny, nx);
	}
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
			if (c == '#') {
				a[i][j] = WALL;
			} else if (c == 'v') {
				a[i][j] = WOLF;
			} else if (c == 'k') {
				a[i][j] = SHEEP;
			}
		}
	}

	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (a[i][j] != WALL && !visited[i][j]) {
				w = 0;
				s = 0;
				dfs(i, j);
				if (s > w)
					ans[0] += s;
				else
					ans[1] += w;
			}
		}
	}

	cout << ans[0] << ' ' << ans[1] << endl;

	return 0;
}
