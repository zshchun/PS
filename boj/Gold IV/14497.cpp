#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
static int n, m, _x1, _y1, x2, y2;
char a[301][301];
bool visited[301][301];
bool found = false;
int ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = 1;
	if (a[y][x] == '1') {
		a[y][x] = '0';
		return;
	} else if (a[y][x] == '#') {
		found = true;
		return;
	}

	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n >> m;
	cin >> _y1 >> _x1;
	cin >> y2 >> x2;
	_y1--; _x1--; y2--; x2--;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			cin >> a[i][j];
	while (!found){
		memset(visited, 0, sizeof(visited));;
		ans++;
		dfs(_y1, _x1);
		if (found) break;
	}
	cout << ans << endl;

	return 0;
}
