#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[251][251];
bool visited[251][251];
int ans, N, M;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int y, int x) {
	if (visited[y][x])
		return;
	visited[y][x] = 1;
	for (int i=0;i<8;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || !a[ny][nx])
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	int i, j;
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
		}
	}
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			if (!visited[i][j] && a[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
