#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, M;
int m[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<P> meltList;
void bfs(int y, int x) {
	queue<P> q;
	int cury, curx;
	if (visited[y][x]) return;
	visited[y][x] = 1;
	q.push(P(y, x));
	while (!q.empty()) {
		tie(cury, curx) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if (!m[ny][nx] && !visited[ny][nx]) {
				q.push(P(ny, nx));
				visited[ny][nx] = 1;
			} else if (m[ny][nx] == 1) {
				if (!visited[ny][nx])
					visited[ny][nx] = 1;
				else
					meltList.push_back(P(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int i, j;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin >> m[i][j];
	
	int ans = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		bfs(1, 1);
		bfs(1, M);
		bfs(N, 1);
		bfs(M, M);
		for (auto &p : meltList) {
			int y = p.first;
			int x = p.second;
			m[y][x] = 0;
		}
		if (meltList.empty()) break;
		meltList.clear();
		ans++;
	}
	cout << ans << '\n';
	return 0;
}

