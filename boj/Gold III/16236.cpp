#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[20][20];
int sz = 2;
int eatten = 0;
int x, y, N;
int visited[20][20];
const pair<int,int> ds[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1},};
vector<pair<int,int>> pos;
int bfs() {
	queue<pair<int,int>> q;
	int a, b;
	int mn = 9999;
	q.push(pair<int,int>(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		tie(a, b) = q.front();
		q.pop();
		if (m[a][b] && m[a][b] < sz) {
			if (mn > visited[a][b]) {
				pos.clear();
				mn = visited[a][b];
				pos.push_back(pair<int,int>(a, b));
			} else if (mn == visited[a][b]) {
				pos.push_back(pair<int,int>(a, b));
			}
		}
		for (auto &p : ds) {
			int yy=a+p.first, xx=b+p.second;
			if (yy < N && yy >= 0 && xx < N && xx >= 0 && !visited[yy][xx] && m[yy][xx] <= sz) {
				q.push(make_pair(yy, xx));
				visited[yy][xx] = visited[a][b] + 1;
			}
		}
	}
	if (mn == 9999)
		return 0;
	else
		return mn-1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				m[i][j] = 0;
				y = i;
				x = j;
			}
		}
	}
	int ans = 0, v;
	while ((v=bfs())) {
		cout << "y:"<<y<<" x:"<<x<<'\n';
		for (auto &p : pos)
			cout << p.first << ":"<<p.second<<'\n';
		cout << '\n';
		m[pos[0].first][pos[0].second] = 0;
		eatten++;
		if (eatten == sz) {
			sz++;
			eatten = 0;
		}
		y = pos[0].first;
		x = pos[0].second;

		ans += v;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans << '\n';
	return 0;
}

