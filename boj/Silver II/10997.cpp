#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, H, W;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool a[500][500];

void dfs(int y, int x, int c, int beg) {
	if (H <= 0 || W <= 0)
		return;
	int w = W;
	int h = H;

	while(w > 0 && h > 0) {
		a[y][x] = 1;
		y += dy[c];
		x += dx[c];
		w -= abs(dx[c]);
		h -= abs(dy[c]);
	} 

	y -= dy[c];
	x -= dx[c];
	if (!beg) {
		if (c & 1) {
			H -= 2;
		} else {
			W -= 2;
		}
	}
	dfs(y, x, (c + 1) % 4, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, i, j;
	cin >> N;
	H = N * 3 + N - 1;
	W = H - 2;
	if (N == 1) {
		cout << "*\n";
		return 0;
	}
	y = H;
	x = W;
	dfs(0, W-1, 0, 1);

	for (i=0;i<y;i++) {
		for (j=0;j<x;j++) {
			if (i == 1 && j > 0)
				break;
			if (a[i][j]) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
