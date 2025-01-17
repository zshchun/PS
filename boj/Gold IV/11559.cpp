#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MAX_Y 12
#define MAX_X  6
int a[MAX_Y][MAX_X];
bool visited[MAX_Y][MAX_X];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x, int c) {
	int ny, nx, t = 0;
	if (a[y][x] != c)
		return 0;
	if (visited[y][x])
		return 0;
	visited[y][x] = 1;
	t++;

	for (int i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < MAX_X && ny < MAX_Y) {
			t += dfs(ny, nx, c);
		}
	}
	return t;
}

void del(int y, int x, int c) {
	int ny, nx;
	if (a[y][x] != c)
		return;
	a[y][x] = 0;
	for (int i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < MAX_X && ny < MAX_Y) {
			del(ny, nx, c);
		}
	}

}

void move_down(int y, int x) {
	for (int i=y+1;i<MAX_Y;i++) {
		if (!a[i][x]) {
			a[i][x] = a[i-1][x];
			a[i-1][x] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, streak = 1, ans = 0, n;
	char c;
	for (i=0;i<MAX_Y;i++) {
		for (j=0;j<MAX_X;j++) {
			cin >> c;
			if (c != '.')
				a[i][j] = c - 'A';
		}
	}
	while (streak != 0) {
		streak = 0;
		memset(visited, 0, sizeof(visited));
		for (i=0;i<MAX_Y;i++) {
			for (j=0;j<MAX_X;j++) {
				if (a[i][j] && !visited[i][j]) {
					n = dfs(i, j, a[i][j]);
					if (n >= 4) {
						streak++;
						del(i, j, a[i][j]);
					}
				}
			}
		}

		if (streak)
			ans++;

		for (i=MAX_Y-2;i>=0;i--) {
			for (j=MAX_X-1;j>=0;j--) {
				if (a[i][j])
					move_down(i, j);
			}
		}
	}
	cout << ans << endl;

	return 0;
}
