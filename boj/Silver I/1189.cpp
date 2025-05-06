#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int R, C, K, ans;
int a[6][6];
bool used[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x, int k) {
	if (k >= K) {
		if (k == K && y == 0 && x == C-1)
			ans++;
		return;
	}

	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] || used[ny][nx])
			continue;
		used[ny][nx] = 1;
		dfs(ny, nx, k+1);
		used[ny][nx] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> R >> C >> K;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> c;
			if (c == 'T')
				a[i][j] = 1;
		}
	}

	used[R-1][0] = 1;
	dfs(R-1, 0, 1);

	cout << ans << endl;

	return 0;
}
