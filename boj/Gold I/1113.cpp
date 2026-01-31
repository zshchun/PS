#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456
int N, M, ans, cnt;
int a[51][51];
bool visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pa> b[10];

bool is_border(int y, int x) {
	if (y <= 0 || x <= 0 || y >= N - 1 || x >= M - 1)
		return true;
	return false;
}

int dfs(int y, int x, int s, int low) {
	if (visited[y][x]) return low;
	visited[y][x] = 1;
	cnt++;
	if (is_border(y, x))
		low = 0;

	for (int i=0;i<4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (a[ny][nx] <= s) {
			low = min(low, dfs(ny, nx, s, low));
		} else {
			low = min(low, a[ny][nx]);
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, v, low;
	char c;
	vector<pa> t;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			a[i][j] = c - '0';
			b[a[i][j]].push_back(pa(i, j));
		}
	}
	for (k=1;k<=9;k++) {
		memset(visited, 0, sizeof(visited));
		for (auto &[y, x] : b[k]) {
			if (visited[y][x]) continue;
			cnt = 0;
			low = dfs(y, x, a[y][x], 9);
			if (low == 0) continue;
			ans += low * cnt - a[y][x] * cnt;
		}
	}
	cout << ans << endl;
	return 0;
}
