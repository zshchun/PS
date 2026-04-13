#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
#define WALL 1
#define Y first
#define X second
int H, W, N, ans;
bool a[1001][1001];
bool visited[1001][1001];
pi pos[10];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int bfs(pi s, pi e) {
	memset(visited[0], 0, sizeof(visited));
	queue<tup> q;
	q.push(tup(s.Y, s.X, 0));
	visited[s.Y][s.X] = 1;
	auto [ey, ex] = e;
	while (!q.empty()) {
		auto [y, x, d] = q.front();
		q.pop();
		if (ey == y && ex == x)
			return d;
		for (int i=0;i<4;i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= H || nx >= W || a[ny][nx] == WALL)
				continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push(tup(ny, nx, d+1));
		}
	}
	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> H >> W >> N;
	char c;
	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) {
			cin >> c;
			if (c == 'X')
				a[i][j] = WALL;
			else if ('1' <= c && c <= '9')
				pos[c-'0'] = pi(i, j);
			else if (c == 'S')
				pos[0] = pi(i, j);
		}
	}

	for (i=1;i<=N;i++)
		ans += bfs(pos[i-1], pos[i]);

	cout << ans << endl;
	return 0;
}
