#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define FINDING 1
#define DONE 2

int visited[1001][1001];
int a[1001][1001];
int ans, cnt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// count cycle
void dfs(int y, int x) {
	visited[y][x] = FINDING;
	int d = a[y][x];
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (!visited[ny][nx])
		dfs(ny, nx);
	else if (visited[ny][nx] == FINDING)
		ans++;
	visited[y][x] = DONE;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, m;
	char c;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> c;
			if (c == 'U') a[i][j] = 0;
			else if (c == 'R') a[i][j] = 1;
			else if (c == 'D') a[i][j] = 2;
			else if (c == 'L') a[i][j] = 3;
		}
	}

	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (!visited[i][j])
				dfs(i, j);
	cout << ans << endl;
	
	return 0;
}
