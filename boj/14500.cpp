#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> ts[5] = {
{{0,0}, {0,1}, {1,0}, {1,1}},
{{0,0}, {0,1}, {0,2}, {0,3}},
{{0,0}, {1,0}, {2,0}, {2,1}},
{{0,0}, {1,0}, {1,1}, {2,1}},
{{0,0}, {0,1}, {1,1}, {0,2}},
};
int m[501][501];
int mx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, k, l;
	int s[8];
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> m[i][j];
		}
	}
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			for (k=0;k<5;k++) {
				memset(s, 0, sizeof(s));
				for (l=0;l<4;l++) { // rotation
					int y = ts[k][l].first;
					int x = ts[k][l].second;
					if (i-x < N && i-x >= 0 && j-y < M && j-y >= 0) s[0] += m[i-x][j-y];
					else s[0] = -9000;
					if (i-y < N && i-y >= 0 && j-x < M && j-x >= 0) s[1] += m[i-y][j-x];
					else s[1] = -9000;
					if (i+x < N && i+x >= 0 && j+y < M && j+y >= 0) s[2] += m[i+x][j+y];
					else s[2] = -9000;
					if (i+y < N && i+y >= 0 && j+x < M && j+x >= 0) s[3] += m[i+y][j+x];
					else s[3] = -9000;
					if (i-x < N && i-x >= 0 && j+y < M && j+y >= 0) s[4] += m[i-x][j+y];
					else s[4] = -9000;
					if (i-y < N && i-y >= 0 && j+x < M && j+x >= 0) s[5] += m[i-y][j+x];
					else s[5] = -9000;
					if (i+x < N && i+x >= 0 && j-y < M && j-y >= 0) s[6] += m[i+x][j-y];
					else s[6] = -9000;
					if (i+y < N && i+y >= 0 && j-x < M && j-x >= 0) s[7] += m[i+y][j-x];
					else s[7] = -9000;
				}
				for (l=0;l<8;l++) {
					mx = max(mx, s[l]);
				}
			}
		}
	}
	cout << mx << '\n';
	return 0;
}
