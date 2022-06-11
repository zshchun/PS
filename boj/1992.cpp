#include <bits/stdc++.h>
using namespace std;
int m[64][64];
string solve(int y, int x, int len) {
	int v = m[y][x];
	int i, j;
	bool same = true;
	for (i=y;i<y+len;i++) {
		for (j=x;j<x+len;j++) {
			if (m[i][j] != v) {
				same = false;
				break;
			}
		}
	}
	if (!same)
		return '(' + solve(y, x, len/2) + solve(y, x+len/2, len/2) + solve(y+len/2, x, len/2) + solve(y+len/2, x+len/2, len/2) + ')';
	return to_string(v);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	char c;
	cin >> n;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) {
			cin >> c;
			m[i][j] = c - '0';
		}
	cout << solve(0, 0, n) << '\n';
	return 0;
}
