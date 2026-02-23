#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans, room;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
bool a[31][31];
bool visited[31][31];

void dfs(int y, int x, int n, int c) {
	if (c >= ans) return;
	if (room == n) {
		ans = min(c, ans);
		return;
	}
	vector<pa> passed;
	for (int i=0;i<4;i++) {
		int moved = n;
		int ny = y + dy[i];
		int nx = x + dx[i];
		while (ny >= 0 && nx >= 0 && ny < N && nx < M && !a[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			passed.push_back(pa(ny, nx));
			ny += dy[i];
			nx += dx[i];
			moved++;
		}
		ny -= dy[i];
		nx -= dx[i];
		if (ny != y || nx != x)
			dfs(ny, nx, moved, c+1);
		for (auto &[ny, nx] : passed)
			visited[ny][nx] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, num = 1;
	char c;
	while (cin >> N >> M) {
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		ans = INF;
		room = 0;

		for (i=0;i<N;i++) {
			for (j=0;j<M;j++) {
				cin >> c;
				if (c == '*') {
					a[i][j] = 1;
				} else {
					room++;
				}
			}
		}
		for (i=0;i<N;i++)
			for (j=0;j<M;j++)
				if (!a[i][j]) {
					visited[i][j] = 1;
					dfs(i, j, 1, 0);
					visited[i][j] = 0;
				}
		if (ans == INF)
			cout << "Case " << num++ << ": -1\n";
		else
			cout << "Case " << num++ << ": " << ans << endl;
	}
	return 0;
}
