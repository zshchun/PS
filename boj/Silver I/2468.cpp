#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[101][101];
bool visited[101][101];
int N, ans = 1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x, int z) {
	int i, nx, ny;

	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || a[ny][nx] <= z)
			continue;
		if (visited[ny][nx])
			continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, z);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, cnt, mx = 0;
	cin >> N;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
			if (a[i][j] > mx)
				mx = a[i][j];
		}
	}

	for (k=1;k<=mx;k++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				if (!visited[i][j] && a[i][j] > k) {
					visited[i][j] = 1;
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		if (cnt > ans)
			ans = cnt;
	}

	cout << ans << endl;
	return 0;
}
