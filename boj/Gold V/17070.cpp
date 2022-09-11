#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, ans;
bool m[17][17];
enum type_t { VERTICAL, HORIZONTAL, DIAGONAL };
void dfs(int y, int x, type_t t) {
	if (y == N && x == N) {
		ans++;
		return;
	}
	if (y > N || x > N)
		return;
	if (t == VERTICAL) {
		if (!m[y+1][x]) {
			dfs(y+1, x, VERTICAL);
		}
	} else if (t == HORIZONTAL) {
		if (!m[y][x+1]) {
			dfs(y, x+1, HORIZONTAL);
		}
	} else if (t == DIAGONAL) {
		if (!m[y+1][x]) {
			dfs(y+1, x, VERTICAL);
		}
		if (!m[y][x+1]) {
			dfs(y, x+1, HORIZONTAL);
		}
	}
	if (!m[y][x+1] && !m[y+1][x+1] && !m[y+1][x]) {
		dfs(y+1, x+1, DIAGONAL);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> m[i][j];
		}
	}
	dfs(1, 2, HORIZONTAL);
	cout << ans << '\n';

	return 0;
}

