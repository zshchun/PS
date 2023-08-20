#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int M, N, K, cnt;;
bool a[101][101];
bool visited[101][101];
vector<int> ans;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
	if (visited[y][x])
		return;
	visited[y][x] = 1;
	cnt++;
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || nx < 0 || nx >= N || ny >= M || a[ny][nx])
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, sy, sx, ey, ex;
	cin >> M >> N >> K;
	for (i=0;i<K;i++) {
		cin >> sx >> sy >> ex >> ey;
		for (j=sy;j<ey;j++) {
			for (k=sx;k<ex;k++) {
				a[j][k] = 1;
			}
		}
	}
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			if (!visited[i][j] && !a[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
