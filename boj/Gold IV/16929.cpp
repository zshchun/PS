#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans;
int visited[51][51];
string s[51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x, char c) {
	if (ans) return;
	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (c != s[ny][nx])
			continue;
		if (visited[ny][nx]) {
			if (visited[y][x] - visited[ny][nx] >= 3) {
				ans = 1;
				break;
			}
			continue;
		}
		visited[ny][nx] = visited[y][x] + 1;

		dfs(ny, nx, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M;
	for (i=0;i<N;i++)
		cin >> s[i];

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				dfs(i, j, s[i][j]);
			}
		}
	}
	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
