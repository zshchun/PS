#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, r1, c1, r2, c2;
int visited[201][201];
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};

void bfs() {
	int r, c, i;
	queue<pa> q;
	q.push(pa(r1, c1));
	visited[r1][c1] = 1;

	while (!q.empty()) {
		tie(r, c) = q.front();
		q.pop();
		if (r == r2 && c == c2)
			break;
		for (i=0;i<6;i++) {
			int ny = r + dy[i];
			int nx = c + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx])
				continue;
			visited[ny][nx] = visited[r][c] + 1;
			q.push(pa(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> r1 >> c1 >> r2 >> c2;

	bfs();

	if (visited[r2][c2])
		cout << visited[r2][c2] - 1 << endl;
	else
		cout << "-1\n";
	return 0;
}
