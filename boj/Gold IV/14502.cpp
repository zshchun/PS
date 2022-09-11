#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a[101][101];
bool visited[101][101];
int N, M, spread;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int y, int x) {
	int cy, cx, nx, ny;
	queue<P> q;
	q.push(P(y, x));
	while (!q.empty()) {
		tie(cy, cx) = q.front();
		q.pop();
		if (visited[cy][cx]) continue;
		visited[cy][cx] = 1;
		if (!a[cy][cx]) spread++;
		for (int i=0;i<4;i++) {
			nx = cx+dx[i]; ny = cy+dy[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !a[ny][nx]) {
				q.push(P(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, c, ans=0;
	vector<P> virus, space;
	cin >> N >> M;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++) {
			cin >> a[i][j];
			if (a[i][j] == 2)
				virus.push_back(P(i, j));
			else if (a[i][j] == 0)
				space.push_back(P(i, j));
		}

	
	for (i=0;i<space.size();i++) {
		for (j=i+1;j<space.size();j++) {
			for (k=j+1;k<space.size();k++) {
				memset(visited, 0, sizeof(visited));
				visited[space[i].first][space[i].second] = 1;
				visited[space[j].first][space[j].second] = 1;
				visited[space[k].first][space[k].second] = 1;
				spread = 3;
				for (auto &p : virus) {
					bfs(p.first, p.second);
				}
				c = space.size() - spread;
				if (c > ans) {
					ans = c;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
