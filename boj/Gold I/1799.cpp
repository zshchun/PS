#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[11][11];
int used[11][11];
int l[20];
int r[20];
int ans[2];
int N;

// nqueen, backtrack
void backtrack(int y, int x, int c) {
	if (x >= N) {
		y++;
		x ^= 1;
		x &= 1;
	}
	if (y >= N) {
		ans[(x+y)&1] = max(ans[(x+y)&1], c);
		return;
	}
	int ld = x - y + N - 1;
	int rd = x + y;
	if (a[y][x] && !l[ld] && !r[rd]) {
		l[ld] = r[rd] = 1;
		backtrack(y, x+2, c+1);
		l[ld] = r[rd] = 0;
	}
	backtrack(y, x+2, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int i, j;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
		}
	}
	backtrack(0, 0, 0);
	backtrack(0, 1, 0);

	cout << ans[0] + ans[1] << endl;
	return 0;
}
