#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int W, H, ans;
int a[51][51];
bool visited[51][51];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int y, int x) {
	if (visited[y][x])
		return;
	visited[y][x] = 1;
	for (int i=0;i<8;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= W || ny >= H || nx < 0 || ny < 0 || !a[ny][nx])
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		for (i=0;i<H;i++)
			for (j=0;j<W;j++)
				cin >> a[i][j];
		memset(visited, 0, sizeof(visited));
		ans = 0;
		for (i=0;i<H;i++) {
			for (j=0;j<W;j++) {
				if (!visited[i][j] && a[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
