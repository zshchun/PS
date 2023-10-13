#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bool visited[11][11];
int price[11][11];
int dy[5] = { 0, 0, 1, -1, 0 };
int dx[5] = { 1, -1, 0, 0, 0 };
int ans = INF;
int N;

void backtrack(int y, int x, int n, int c) {
	if (n == 3) {
		ans = min(ans, c);
		return;
	}

	bool ok = true;
	for (int i=0;i<5;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) {
			ok = false;
			break;
		}
	}

	int tx = x;
	int ty = y;
	if (x+1 < N)
		tx++;
	else if (y+1 < N) {
		ty++;
		tx = 0;
	} else
		return;

	if (ok) {
		int sum = 0;
		for (int i=0;i<5;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			sum += price[ny][nx];
			visited[ny][nx] = 1;
		}
		backtrack(ty, tx, n+1, c+sum);

		for (int i=0;i<5;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			visited[ny][nx] = 0;
		}
	}
	backtrack(ty, tx, n, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> price[i][j];

	backtrack(0, 0, 0, 0);
	cout << ans << endl;

	return 0;
}
