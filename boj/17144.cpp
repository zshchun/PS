#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int R, C, T;
int m[51][51];
int d[51][51];
vector<int> ac;
inline void copy(int s1[51][51], int s2[51][51]) {
	int i, j;
	for (i=0;i<R;i++)
		for (j=0;j<C;j++)
			s1[i][j] = s2[i][j];
}
void circulator(int n, vector<P> &ws) {
	int p=0, pp, x=1, y=n;
	for (P &w : ws) {
		while (y+w.first >= 0 && y+w.first < R && x+w.second >= 0 && x+w.second < C && d[y][x] != -1) {
			int wy=y+w.first, wx=x+w.second;
			pp = d[y][x];
			d[y][x] = p;
			p = pp;
			y = wy;
			x = wx;
		}
	}
}
P ds[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<P> upside {P(0, 1), P(-1, 0), P(0, -1), P(1, 0)};
vector<P> downside {P(0, 1), P(1, 0), P(0, -1), P(-1, 0)};
int main() {
	ios_base::sync_with_stdio(false);
	vector<P> wind;
	cin.tie(0);
	int i, j;
	cin >> R >> C >> T;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			cin >> m[i][j];
			if (j == 0 && m[i][j] == -1) {
				ac.push_back(i);
			}
		}
	}
	while (T--) {
		copy(d, m);
		for (i=0;i<R;i++) {
			for (j=0;j<C;j++) {
				if (m[i][j]) {
					for (P &p : ds) {
						int dy = i+p.first, dx = j+p.second;
						if (dx >= 0 && dy >= 0 && dx < C && dy < R && !(dx == 0 && (dy == ac[0] || dy == ac[1]))) {
							d[dy][dx] += m[i][j] / 5;
							d[i][j] -= m[i][j] / 5;
						}
					}
				}
			}
		}
		circulator(ac[0], upside);
		circulator(ac[1], downside);
		copy(m, d);
	}
	int ans = 0;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (m[i][j] > 0) {
				ans += m[i][j];
			}
		}
	}
	cout << ans << '\n';

	return 0;
}

