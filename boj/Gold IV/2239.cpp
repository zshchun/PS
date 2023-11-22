#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[10][10];
int rb[10];
int cb[10];
int bb[10];
bool found = false;
inline int blk_idx(int y, int x) {
	return (y-1) / 3 * 3 + (x-1)/3;
}

void backtrack(int y, int x) {
	if (found) return;
	if (y > 9) {
		for (int i=1;i<=9;i++) {
			for (int j=1;j<=9;j++) {
				cout << a[i][j];
			}
			cout << "\n";
		}
		found = true;
		return;
	}
	if (a[y][x] == 0) {
		for (int i=1;i<=9;i++) {
			if (rb[y] & (1<<i)) continue;
			if (cb[x] & (1<<i)) continue;
			int b = blk_idx(y, x);
			if (bb[b] & (1<<i)) continue;
			rb[y] |= 1 << i;
			cb[x] |= 1 << i;
			bb[b] |= 1 << i;
			a[y][x] = i;
			if (x >= 9)
				backtrack(y+1, 1);
			else
				backtrack(y, x+1);
			a[y][x] = 0;
			rb[y] &= ~(1 << i);
			cb[x] &= ~(1 << i);
			bb[b] &= ~(1 << i);
		}
	} else if (x >= 9)
		backtrack(y+1, 1);
	else
		backtrack(y, x+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	char c;
	for (i=1;i<=9;i++) {
		for (j=1;j<=9;j++) {
			cin >> c;
			k = c - '0';
			if (k) {
				a[i][j] = k;
				rb[i] |= 1 << k;
				cb[j] |= 1 << k;
				int b = blk_idx(i, j);
				bb[b] |= 1 << k;

			}
		}
	}

	backtrack(1, 1);

	return 0;
}
