#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, K, ans = -INF;
int a[11][11];
bool visited[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void backtrack(int y, int x, int n, int c) {
	if (n == K) {
		if (ans < c)
			ans = c;
		return;
	}
	if (y >= N) return;
	int nx = x;
	int ny = y;
	if (x+1 < M) {
		nx++;
	} else {
		ny++;
		nx = 0;
	}
	bool ok = true;
	for (int i=0;i<4;i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= 0 && xx >= 0 && yy < N && xx < M && visited[yy][xx]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		visited[y][x] = 1;
		backtrack(ny, nx, n+1, c+a[y][x]);
		visited[y][x] = 0;
	}
	backtrack(ny, nx, n, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M >> K;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
		}
	}
	backtrack(0, 0, 0, 0);
	cout << ans << endl;

	return 0;
}
