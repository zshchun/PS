#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//int m[401][401];
string s[401];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, x1, x2, y1, y2, x3, x4, y3, y4;
	cin >> T;
	while(T--) {
		cin >> N;
		x1 = x2 = y1 = y2 = 0;
		for (i=1;i<=N;i++) {
			cin >> s[i];
			for (j=1;j<=N;j++) {
				if (s[i][j-1] == '*') {
					if (x1) {
						y2 = i;
						x2 = j;
					} else {
						y1 = i;
						x1 = j;
					}
				}
//				m[i][j] = s[j] == '.'
			}
		}
		y3 = y1;
		x3 = x2;
		y4 = y2;
		x4 = x1;
		if (y1 == y2) {
			if (y1+1 <= N) {
				y3 = y4 = y1+1;
			} else if (y1-1 >= 1) {
				y3 = y4 = y1-1;
			}
		} else if (x1 == x2) {
			if (x1+1 <= N) {
				x3 = x4 = x1+1;
			} else if (x1-1 >= 1) {
				x3 = x4 = x1-1;
			}
		}
		s[y3][x3-1] = '*';
		s[y4][x4-1] = '*';
		for (i=1;i<=N;i++) {
			cout << s[i] << '\n';
		}
	}
	return 0;
}
